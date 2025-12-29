#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int port = 9999; // The port we want to open

    // 1. Create socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Attach socket to the port 9999
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // 3. Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d. Run your scan now...\n", port);

    // Keep it open until we manually stop it (Ctrl+C)
    while(1) {
        sleep(1);
    }

    return 0;
}

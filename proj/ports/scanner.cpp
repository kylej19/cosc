#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char* target_ip = "127.0.0.1"; // Localhost
    int target_port = 9999;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(target_port);
    
    // Convert IP address from text to binary
    inet_pton(AF_INET, target_ip, &serv_addr.sin_addr);

    // Try to connect
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Port " << target_port << " is CLOSED" << std::endl;
    } else {
        std::cout << "Port " << target_port << " is OPEN" << std::endl;
    }

    close(sock);
    return 0;
}

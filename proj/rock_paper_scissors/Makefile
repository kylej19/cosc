CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
TARGET = rock-paper-scissors
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -fv $(TARGET) $(OBJECTS)

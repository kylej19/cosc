CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Wshadow -std=c++20
TARGET = guessing-game
SOURCES = main.cpp input_validation.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

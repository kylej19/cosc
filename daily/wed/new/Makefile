CXX = g++-15
CXXFLAGS = -Wall -Wextra -Wpedantic -Wshadow -std=c++20
TARGET = testrun
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$TARGET: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean: rm -fv $(TARGET) $(OBJECTS)

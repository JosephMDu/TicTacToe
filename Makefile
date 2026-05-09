# Instructions
# 	1. type "make" into your terminal and enter
#	2. use "./game" to execute

# Compiler and flags
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Target executable name
TARGET = game

# Source files and Object files
SRCS = AIPlayer.cpp Board.cpp HumanPlayer.cpp Player.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule: build the executable
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean

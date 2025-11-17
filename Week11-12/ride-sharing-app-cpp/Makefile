# Makefile for Ride Sharing App

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Target executable
TARGET = ride_sharing_app

# Source files
SOURCES = main.cpp Ride.cpp StandardRide.cpp PremiumRide.cpp Driver.cpp Rider.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = Ride.h StandardRide.h PremiumRide.h Driver.h Rider.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build successful! Run ./$(TARGET) to execute."

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete."

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run


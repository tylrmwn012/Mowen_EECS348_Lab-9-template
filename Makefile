CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = matrix_program

SRCS = main.cpp

$(TARGET): $(SRCS) matrix.hpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

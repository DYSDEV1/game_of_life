CXX = g++ 
CXXFLAGS = -Wall -g -O0 -std=c++17

BUILD_DIR = build

TARGET = $(BUILD_DIR)/gameoflife
SRCS = cell.cpp board.cpp main.cpp

OBJS = $(BUILD_DIR)/cell.o $(BUILD_DIR)/board.o $(BUILD_DIR)/main.o

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf $(BUILD_DIR)
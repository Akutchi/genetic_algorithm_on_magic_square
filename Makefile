CXX = g++
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -g
SRC= ./src/
INC= ./include/
BUILD= ./build/

.PHONY: all clear

all: main

main: $(BUILD)main.o $(BUILD)Individual.o
	$(CXX) -g $^ -o $(BUILD)$@

$(BUILD)main.o: $(SRC)main.cpp  
	$(CXX) -I$(INC) -c -g $< -o $@

$(BUILD)%.o: $(SRC)%.cpp $(INC)%.h
	$(CXX) -I$(INC) -c -g $< -o $@

clear:
	rm -f $(BUILD)*



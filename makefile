#!/bin/sh
CC = g++
CCFLAGS =-Wall -std=c++11 -g
CLEAN = rm -f
PROG_NAME = a.out
OBJECT_FILES = *.o
SOURCE_FILES = myString.cpp main.cpp 
TEST_FILES = myStringTests.cpp

$(PROG_NAME): $(OBJECT_FILES)
	$(CC) $(CCFLAGS) -o $@ $^

$(OBJECT_FILES): $(SOURCE_FILES)
	$(CC) $(CCFLAGS) -c $^

clean:
	$(CLEAN) *.o $(PROG_NAME) test runner.cpp

# test: 
# 	$(CC) $(CCFLAGS) test.cpp myString.cpp -o test
	

test: runner.cpp
	$(CC) $(CCFLAGS) runner.cpp myString.cpp -o test

runner.cpp: $(TEST_FILES) myString.cpp
	cxxtestgen --error-printer -o runner.cpp $(TEST_FILES)
#!/bin/sh
CC = g++
CCFLAGS =-Wall -std=c++11 -g
CLEAN = rm -f
PROG_NAME = a.out
OBJECT_FILES = *.o
SOURCE_FILES = myString.cpp main.cpp 

$(PROG_NAME): $(OBJECT_FILES)
	$(CC) $(CCFLAGS) -o $@ $^

$(OBJECT_FILES): $(SOURCE_FILES)
	$(CC) $(CCFLAGS) -c $^

clean :
	$(CLEAN) *.o $(PROG_NAME)

test : 
	$(CC) $(CCFLAGS) test.cpp myString.cpp -o test
	

# a.out: fraction.o main.o
# 	g++ -o fraction.o main.o

# fraction.o: fraction.c fraction.h
# 	g++ -c fraction.c 

# main.o: main.c
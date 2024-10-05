CXX = gcc
TARGET = main.c
OUTPUT = main

.PHONY: all

all: 
	$(CXX) -o $(OUTPUT) $(TARGET)

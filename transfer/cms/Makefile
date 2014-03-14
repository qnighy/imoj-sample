#!/usr/bin/make -f

CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -g
OBJS = manager user_program

SOL_DIR = ../sol/sol_partial
INPUT = ../in/sample-01.txt

.PHONY: all clean run run1 run2

all: manager

clean:
	$(RM) manager user_program fifo1_in fifo1_out fifo2_in fifo2_out

user_program: stub.cpp $(SOL_DIR)/playerA.cpp $(SOL_DIR)/playerB.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

run: manager
	rm -f fifo1_in fifo1_out fifo2_in fifo2_out
	mkfifo fifo1_in fifo1_out fifo2_in fifo2_out
	./manager fifo1_in fifo1_out fifo2_in fifo2_out < $(INPUT)

run1: user_program
	./user_program 0 fifo1_out fifo1_in

run2: user_program
	./user_program 1 fifo2_out fifo2_in

#!/usr/bin/make -f

CC = gcc
CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -g
LDFLAGS = -lm
OBJS = sol sol_partial sol.o sol_partial.o grader.o

all: $(OBJS)

clean:
	$(RM) $(OBJS)

sol_partial: sol_partial.o grader.o

sol: sol.o grader.o

sol_partial.o: grader.h

sol.o: grader.h

grader.cpp: ../dist/grader.cpp
	cp $< $@

grader.h: ../dist/grader.h
	cp $< $@

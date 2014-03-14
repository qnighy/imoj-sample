#!/usr/bin/make -f

CC = gcc
CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -g
CPPFLAGS =
LDLIBS = -lm
OBJS = main grader.o playerA.o playerB.o

.PHONY: all clean

all: main

clean:
	$(RM) $(OBJS)

grader.cpp: ../../dist/grader.cpp
	cp $< $@

%.h: ../../dist/%.h
	cp $< $@

main: playerA.o playerB.o grader.o
	$(CXX) $(CXXFLAGS) -o $@ $(LDLIBS) playerA.o playerB.o grader.o

playerA.o: playerA.h playerAlib.h
playerB.o: playerB.h playerBlib.h
grader.o: playerA.h playerB.h

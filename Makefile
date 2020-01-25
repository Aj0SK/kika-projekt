CFLAGS = -Wall -O2 -std=c++17
CC = g++

all: writeBMPDemo

writeBMPDemo:
	${CC} ${CFLAGS} writeBMPDemo.cpp && ./a.out

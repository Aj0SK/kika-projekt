CFLAGS = -Wall -O2 -std=c++17
CC = g++

all: writeBMPDemo loadMeshDemo

writeBMPDemo:
	${CC} ${CFLAGS} writeBMPDemo.cpp && ./a.out

loadMeshDemo:
	${CC} ${CFLAGS} loadMeshDemo.cpp objLoad.cpp && ./a.out

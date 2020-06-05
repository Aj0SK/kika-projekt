CFLAGS = -Wall -O2 -std=c++17
CC = g++
SRC = src

all: writeBMPDemo loadMeshDemo

writeBMPDemo:
	${CC} ${CFLAGS} $(SRC)/writeBMPDemo.cpp && ./a.out

loadMeshDemo:
	${CC} ${CFLAGS} $(SRC)/loadMeshDemo.cpp $(SRC)/objLoad.cpp && ./a.out
	
sample:
	${CC} ${CFLAGS} $(SRC)/sample.cpp $(SRC)/objLoad.cpp && ./a.out

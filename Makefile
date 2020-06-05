CFLAGS = -Wall -O2 -std=c++17
CC = g++
SRC = src
SAMPLES = samples

all: samples

samples: writeBMPDemo loadMeshDemo sample1

writeBMPDemo:
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/writeBMPDemo.cpp && ./a.out

loadMeshDemo:
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/loadMeshDemo.cpp $(SRC)/objLoad.cpp && ./a.out
	
sample1:
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/sample.cpp $(SRC)/objLoad.cpp && ./a.out

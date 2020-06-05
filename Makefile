CFLAGS = -Wall -O2 -std=c++17
CC = g++
SRC = src
SAMPLES = samples

all: samples

samples: writeBMPDemo loadMeshDemo sample1 sample2

writeBMPDemo:
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/writeBMPDemo.cpp

loadMeshDemo:
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/loadMeshDemo.cpp $(SRC)/objLoad.cpp
	
sample1:
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/sample1.cpp $(SRC)/objLoad.cpp

sample2:
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/sample2.cpp $(SRC)/objLoad.cpp

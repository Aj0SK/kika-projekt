CFLAGS = -Wall -O2 -std=c++17 -fsanitize=address
CC = clang++
SRC = src
SAMPLES = samples
BUILD = build
RUN = run

all: prepare samples

prepare:
	rm -r -f $(BUILD) $(RUN) && mkdir $(BUILD) $(RUN)

samples: ray_tracing writeBMPDemo loadMeshDemo sample1 sample2 sample3

objLoad.o:
	${CC} ${CFLAGS} -c $(SRC)/objLoad.cpp -o $(BUILD)/objLoad.o

ray_tracing: prepare objLoad.o
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/ray_tracing.cpp -o $(RUN)/ray_tracing.out

writeBMPDemo:
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/writeBMPDemo.cpp

loadMeshDemo: objLoad.o
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/loadMeshDemo.cpp $(BUILD)/*.o -o $(RUN)/loadMeshDemo.out
	
sample1: objLoad.o
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/sample1.cpp $(BUILD)/*.o -o $(RUN)/sample1.out

sample2: objLoad.o
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/sample2.cpp $(BUILD)/*.o -o $(RUN)/sample2.out

sample3: objLoad.o
	${CC} ${CFLAGS} -I $(SRC) $(SAMPLES)/sample3.cpp -o $(RUN)/sample3.out

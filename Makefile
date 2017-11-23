FLAGS = -Wall
SRCS = $(wildcard *.cpp)
OBJS = ${SRCS:.cpp=.o}

.PHONY: all clean mrproper

all: main

main: main.cpp $(OBJS)
	g++ $(FLAGS) $(OBJS) -o main

clean:
	rm -rf *.o *~ main

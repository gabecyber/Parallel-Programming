EXECS = hello_world_omp  hello_world_omp_v3

CC = g++
CFLAGS = -Wall
LFLAGS = -fopenmp -lm

all: $(EXECS)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

clean:
	rm -f a.out $(EXECS)

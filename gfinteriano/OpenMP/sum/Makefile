EXECS = sum_omp sum_omp_v3 sum_omp_v4

CC = g++
CFLAGS = -Wall
LFLAGS = -fopenmp -lm

all: $(EXECS)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

clean:
	rm -f a.out $(EXECS)

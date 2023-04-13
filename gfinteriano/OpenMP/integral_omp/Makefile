EXECS = integral_omp integral_omp_for  integral_omp_reduction

CC = g++
CFLAGS = -Wall
LFLAGS = -fopenmp -lm

all: $(EXECS)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

clean:
	rm -f a.out $(EXECS)

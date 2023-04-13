EXECS= manager worker

MPICC=mpicc

all: $(EXECS)

%: %.c
	$(MPICC) $^ -o $@

clean:
	rm -f a.out $(EXECS)

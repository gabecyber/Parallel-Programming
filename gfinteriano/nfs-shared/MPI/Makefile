EXECS=send_recv

MPICC=mpicc

all: $(EXECS)

%: %.c
	$(MPICC) $^ -o $@

clean:
	rm -f a.out $(EXECS)

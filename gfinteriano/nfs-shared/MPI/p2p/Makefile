EXECS=send_recv check_status probe

MPICC=mpicc

all: $(EXECS)

%: %.c
	$(MPICC) $^ -o $@

clean:
	rm -f a.out $(EXECS)

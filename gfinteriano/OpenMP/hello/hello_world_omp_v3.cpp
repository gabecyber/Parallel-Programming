#include <stdio.h>
#include <omp.h>
int main(int argc, char** argv){
	int threadcnt = 8;
	omp_set_num_threads(threadcnt);

	int x[threadcnt];

	#pragma omp parallel
	{
	int thread_id = omp_get_thread_num();
	x[thread_id]=thread_id;
	}

	for(int i=0; i<threadcnt; i++){
	printf("x[%d]=%d\n",i, x[i]);
	}
	return 0;
}

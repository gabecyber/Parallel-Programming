#include <stdio.h>
#include <omp.h>
int  thread_count=atoi(args[]);
	int main (int argc, char** argv){
	#pragma omp parallel
{
	int thread_id;
	
	thread_id = omp_get_thread_num();
	printf("hello from thread: %d\n", thread_id);
	}
	return 0;
}

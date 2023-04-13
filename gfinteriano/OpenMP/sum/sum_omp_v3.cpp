#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int main(int argc, char** argv){
int count = atoi(argv[1]);
omp_set_num_threads(4);
int partial_sum,total_sum;

#pragma omp parallel private(partial_sum) shared(total_sum)
{
	partial_sum = 0;
	total_sum = 0;
		
	//int localStart = thread_id*2;
	//int localEnd = localStart +2;
	 //for(int i =localStart; i<localEnd; i++){
	 //partial_sum +=i;

	 //}
	#pragma omp for

	for (int i = 0; i<count; i++){
	partial_sum +=i;
	}
	printf("partial_sum = %d\n", partial_sum);
	#pragma omp critical
{
	total_sum += partial_sum;
	}
}

	printf("total_sum=%d\n", total_sum);
	return 0;
}

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int main(int argc, char** argv){
int count = atoi(argv[1]);
omp_set_num_threads(4);
int sum=0;

#pragma omp parallel
{
	//sum = 0;


	#pragma omp for reduction(+:sum)
	for (int i = 0; i<count; i++){
		sum +=i;
	}
}

	printf("total_sum=%d\n",sum);
	return 0;
}

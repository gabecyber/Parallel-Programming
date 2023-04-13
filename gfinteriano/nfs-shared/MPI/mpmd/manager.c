#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLEN 100
char buff[MAXLEN];

int main(){
MPI_Init(NULL, NULL);
MPI_Status st;
int procNum;
MPI_Comm_size(MPI_COMM_WORLD, &procNum);
while(--procNum){
	MPI_Recv(buff, MAXLEN, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &st);

	int aux;
	MPI_Get_count(&st, MPI_CHAR, &aux);
	buff[aux] = 0;
	printf("%s\n", buff);
}
MPI_Finalize();
}

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	MPI_Init(NULL, NULL);
	int world_rank;
MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);
int number;
if (world_rank == 0) {
	number = -1;
	MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
}
 else if (world_rank == 1) {
	MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
char processor_name[MPI_MAX_PROCESSOR_NAME];
int name_len;
MPI_Get_processor_name (processor_name, &name_len);

	printf("Process one %s received number %d from process 0\n",processor_name, number);
	}
	MPI_Finalize();
}

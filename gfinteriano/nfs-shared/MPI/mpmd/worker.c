#include <sprint.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define MAXLEN 100
char *greetings[] = { "Hello", "Hi", "Awaiting your command" };
char buff[MAXLEN];

int main (int argc, char **argv)
{
  struct timeval tv;
  gettimeofday(&tv,NULL);
  // unsigned long time_in_micros = 1000000 * tv.tv_sec + tv.tv_usec;//find the microseconds for seeding srand()
  unsigned long time_in_tenthsecs = 10 * tv.tv_sec + tv.tv_usec/100000;//find the tenth of seconds for seeding srand()
  srand(time_in_tenthsecs);

  MPI_Init (NULL, NULL);
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);
  int grID = rand() % 3;
  
 sprintf(buff, "Node %i on %s says %s", rank , processor_name, greetings[grID]);

MPI_Send(buff, strlen(buff)
  
  MPI_Finalize ();
}

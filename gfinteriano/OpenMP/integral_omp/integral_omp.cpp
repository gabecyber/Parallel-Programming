#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <memory>
#include <omp.h>

using namespace std;

//---------------------------------------
double testf (double x)
{
  return x * x + 2 * sin (x);
  // return cos (x);
 // return 10;
}

//---------------------------------------
double integrate (double st, double en, int div, double (*f) (double))
{
  double localRes = 0;
	
	// -------------------
	// To be completed ...
	// -------------------
	double step =(en-st)/div;
	double x;
	x=st;
	localRes = f(st)+ f(en);
	localRes /=2;

	for(int i =1; i<div; i++)
	{
	x += step;
	localRes += f(x);
	}
	localRes *= step;
	  return localRes;
}

//---------------------------------------
int main (int argc, char *argv[])
{

  if (argc == 1)
    {
      cerr << "Usage " << argv[0] << " start end divisions\n";
      exit (1);
    }
  double start, end;
  int divisions;
  start = atof (argv[1]);
  end = atof (argv[2]);
  divisions = atoi (argv[3]);

  // get the number of threads for next parallel region
  int N = omp_get_max_threads ();
  if (divisions < N)
    {
      cerr << "\"Divisions\" needs to be at least " << N << endl;
      exit (1);
    }
  
  if (divisions % N !=0) {
  	divisions = (divisions / N) * N;    // make sure divisions is a multiple of N
  	cout << "\"Divisions\" has been casted to " << divisions << endl;
  }

  double step = (end - start) / divisions;

  // allocate memory for the partial results
  double partial[N];

#pragma omp parallel
  {
	int localDiv = divisions / N;
	int ID = omp_get_thread_num();
	double localStart = start + ID * localDiv *step;
	double localEnd = localStart + localDiv * step ;
	partial[ID] = integrate(localStart, localEnd, localDiv, testf);
	
	// -------------------
		// To be completed ...
		// -------------------
  }

  // reduction step
  double finalRes = partial[0];
  for (int i = 1; i < N; i++)
    finalRes += partial[i];

  cout << "Final result = " << finalRes << endl;
  return 0;
}


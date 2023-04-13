
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

using namespace std;

//---------------------------------------
double testf (double x)
{
  return x * x + 2 * sin (x);
}

//---------------------------------------
double integrate (double st, double en, int div, double (*f) (double))
{
	double partialRes = 0;
	int N = omp_get_max_threads();
	if(div < N) {
		cerr << "\"Divisions\" needs to be at least " << N << endl;
		exit(1);
	}
	
	if (div % N !=0) {
		div = (div/N) *N;
		cout << "\" Divisions\" has been casted to"  << div << endl;
	}
#pragma omp parallel 
{


	double step = (en - st) / div;
	#pragma omp for reduction(+:partialRes)
		for(int i = 0; i < div; i++){
			double x = st +(i*step);
			partialRes += ((f(x) + f(x +step)) * step/2);
		}
	


   }
	return partialRes;
}	
	// -------------------------------------
  // To be completed using OMP for loop...
	// -------------------------------------


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

  double finalRes = integrate (start, end, divisions, testf);

  cout << finalRes << endl;

  return 0;
}


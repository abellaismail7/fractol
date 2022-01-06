
//0 => 100
//50 => 250
//0 => 50
//0 => 0
#include <math.h>
double map (double n, double f1, double t1, double f2, double t2)
{
	double def1 = t1 - f1;
	double def2 = t2 - f2;
	double mv = def2 / def1;

	return f2 + (n - f1) * mv;
}


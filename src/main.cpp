#include "matrix.h"
#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
	Mat3f x(2.0f, 3.0f, 8.0f, 6.0f, 0.0f, -3.0f, -1.0f, 3.0f, 2.0f);
	Mat3f y(2.0f, 3.0f, 8.0f, 6.0f, 0.0f, -3.0f, -1.0f, 3.0f, 2.0f);
	cout << x.Det() << endl;
	x.InverseGaussian();
	y.Inverse();
	cout << x << endl;
	cout << y << endl;
	return 0;
}


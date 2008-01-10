#include "vec.h"
#include "matrix.h"
#include "functions.h"
#include <iostream>

using namespace std;
using namespace MathLib;


int main()
{
	Vector v(2.0f, 0.0f, 0.0f);
	Matrix trans = MatrixTranslation(trans, 1.0f, 0.0f, 0.0f);
	//Matrix scale = MatrixScaling(scale, 1.0f, 1.0f, 1.0f);
	Matrix rot = MatrixRotationZ(rot, DegreesToRadians(90.0f) );

	v.Transform(trans).Transform(rot);
	
	cout << v << endl;
	cout << endl;
	cout << rot << endl;
	
	return 0;
}


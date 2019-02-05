#include <iostream>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

int main()
{
	TMatrix<double> A(2), B(2);
	A[0][0] = 1;
	A[1][0] = 2;
	A[1][1] = 1;
	cout << A << endl;

	B[0][0] = 1;
	B[1][0] = 2;
	B[1][1] = 1;
	cout << B << endl;

	TMatrix<double> C(2);
	C = A + B;
	cout << C <<endl;
	return 0;

}
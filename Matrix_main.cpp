#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	cout << "메트릭스 테스트" << endl;
	Matrix m1(2, 3);
	m1.doPrint();
	cout << endl;
	m1.doTranspose();
	m1.doPrint();
	cout << endl;
	Matrix m2(2, 3);
	(m1*m2).doPrint();
}
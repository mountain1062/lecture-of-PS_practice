#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	cout << "��Ʈ���� �׽�Ʈ" << endl;
	Matrix m1(2, 3);
	m1.doPrint();
	cout << endl;
	m1.doTranspose();
	m1.doPrint();
	cout << endl;
	Matrix m2(2, 3);
	(m1*m2).doPrint();
}
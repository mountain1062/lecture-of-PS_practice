#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	cout << "메트릭스 테스트" << endl;
	Matrix m1(2, 3);
	m1.doPrint();
	m1.doTranspose();
	m1.doPrint();
	Matrix m2(2, 3);
	//(m1.multi(m2)).doPrint();
}
#include <iostream>
#include <string>
using namespace std;

string deci_to_any(int n, int radix) {
	string s; int r;
	while (n != 0) {
		r = n % radix;
		n = n / radix;
		if (r > 9) s = (char)('A' + r - 10) + s;
		else s = (char)('0' + r) + s;
	}
	return s;
}

double power(double x, int n) {
	//무식
	double result = 1.0;
	for (int i = 0; i < n; i++) {
		result = result * x;
	}
	//메모제이션

}
int main() {
	cout << deci_to_any(140, 8) << endl;//214
	cout << deci_to_any(140, 16) << endl;//8C //11이상 숫자를 알파벳으로 표기하는 예외처리
	
}
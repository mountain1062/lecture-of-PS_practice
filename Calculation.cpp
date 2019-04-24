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
	double result1 = 1.0;
	for (int i = 0; i < n; i++) {
		result1 = result1 * x;
	}
	//반복 횟수 줄이기 (일종 분할정복?)
	double result2 = 1.0;
	while (n > 0) {
		if (n % 2 == 1) result2 *= x;
		x *= x;
		n /= 2;
	}

}

//분수의 실수 표현 (n/d를 소수점 아래 k개 출력)
void print_real(int n, int d, int k) {
	cout << n / d << '.';
	for (int i = 0; i < k; i++) {
		n = (n%d) * 10;
		cout << n / d;
	}
}

int main() {
	cout << deci_to_any(140, 8) << endl;//214
	cout << deci_to_any(140, 16) << endl;//8C //11이상 숫자를 알파벳으로 표기하는 예외처리

}
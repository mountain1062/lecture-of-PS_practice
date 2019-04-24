#include <iostream>
using namespace std;
double result1 = 1, result2 = 1;
int _cnt1, _cnt2;

void power(int x, int n) {
	
	for (int i = 0; i < n; i++) {
		result1 *= x;
		_cnt1++;
	}
	
	while(n > 0) {
		if (n % 2 == 1)result2 *= x;
		x *= x;
		n /= 2;
		_cnt2++;
	}
}

void print_real(int n, int d, int k) {
	cout << n / d << '.';
	for (int i = 0; i < k; i++) {
		n = (n%d) * 10;
		cout << n / d;
	}
}

int main() {
	print_real(9, 7, 10);
	/*power(5, 45);
	cout << result1 << ' ' << _cnt1 << endl;
	cout << result2 << ' ' << _cnt2 << endl;
*/
}
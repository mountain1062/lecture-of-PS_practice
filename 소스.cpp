#include <iostream>
using namespace std;
double result1 = 1, result2 = 1;
int _cnt1, _cnt2;

int Fibo(int n) {
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int fibo(int n)
{
	//비효율적 --> 시간 多
	if (n == 0 || n == 1) return 1;
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	cout << Fibo(5) << endl;
	cout << fibo(5) << endl;
}
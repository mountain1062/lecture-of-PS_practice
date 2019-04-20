#include<iostream>
using namespace std;
int _count = 0;
int _count2 = 0;
int _count3 = 0;
//재귀함수의 핵심 초기항 을 구하고 다음항 과의 관계를 구한다. x^0은 1 
//double power(double x, int n)
//{
//	if (n == 0) return 1.0;
//	power(x, n - 1) * x;
//}

int factorial(int n)//->n!
{
	if (n == 1) return 1;
	return n * (factorial(n - 1));
}
void factorial_memo(int n, int target, int*memo) {
	_count++;
	if (n == 1) {
		memo[1] = 1;
		factorial_memo(n + 1, target, memo);
	}
	if (1 < n&&n <= target) {
		memo[n] = n * memo[n - 1];
		factorial_memo(n + 1, target, memo);
	}
}

int fibo(int n)
{
	//비효율적 --> 시간 多
	_count++;
	if (n == 0 || n == 1) return 1;
	return fibo(n - 1) + fibo(n - 2);
}
//메모이제이션을 이용한 fibo구현 ( DP )
void fibo_memo(int n, int *memo, int target) {
	_count2++;
	memo[0] = memo[1] = 1;
	if (n <= target) {
		memo[n] = memo[n - 1] + memo[n - 2];
		fibo_memo(n + 1, memo, target);
	}
}
//메모이제이션을 이용한 fibo구현 by 교수님
int fibo_memo_pro(int n, int* memo) {
	_count3++;
	if (memo[n]) return memo[n]; //메모되어 있으면 리턴
	if (n == 0 || n == 1) {
		/*memo[n] = 1;
		return 1;*/
		return memo[n] = 1;
	}
	/*memo[n] = fibo_memo_pro(n - 1,memo) + fibo_memo_pro(n - 2,memo);
	return memo[n];*/
	//위 문장을 줄여서 아래처럼 쓸수 있음 (평가값 어쩌구)
	return memo[n] = fibo_memo_pro(n - 1, memo) + fibo_memo_pro(n - 2, memo);
}
int combination_common(int n, int r) {
	if (r == 0 || r == n) return 1;
	return combination_common(n - 1, r) + combination_common(n - 1, r - 1);
}
int combination_memo_by_baek(int n, int r) {
	_count++;
	int *memo_factoral;
	memo_factoral = new int[n + 1];
	memset(memo_factoral, 0, sizeof(int)*(n + 1));
	factorial_memo(1, n, memo_factoral);
	int result = memo_factoral[n] / (memo_factoral[r] * memo_factoral[n - r]);
	return result;
}
int combi_memo_by_pro(int n, int r, int** memo) {
	_count2++;
	if (memo[n][r])return memo[n][r];
	if (r == 0 || n == r) return memo[n][r] = 1;
	return combi_memo_by_pro(n - 1, r - 1, memo) + combi_memo_by_pro(n - 1, r, memo);
}

int main()
{
	//int n = 10;
	////일반적 fibo
	//cout << "common_fibo" << endl;
	//cout << "value : " << fibo(n) << endl;
	//cout << "visit count : " << _count << '\n' << endl;

	//메모이제이션을 이용한 fibo
	//int* memo;//구한 값을 저장할 배열
	//memo = new int[n + 1];
	//memset(memo, 0, sizeof(int)*(n + 1));
	//fibo_memo(2, memo, n);
	//cout << "DP fibo by baek" << endl;
	//cout << "value : " << memo[n] << endl;
	//cout <<"visit count : "<< _count2 <<'\n'<< endl;

	//int* memo2;
	//memo2 = new int[n + 1];
	//memset(memo2, 0, sizeof(int)*(n + 1));
	//cout << "DP fibo by pro" << endl;
	//cout <<"value : "<< fibo_memo_pro(n, memo2) << endl;
	//cout << "visit count : " << _count3 << '\n' << endl;


	/////////////////////////////펙토리얼 테스트//////////////////////////////////////////////
	/*int n = 5;
	int * memo_fact;
	memo_fact = new int[n + 1];
	memset(memo_fact, 0, sizeof(int)*(n + 1));
	factorial_memo(1, n, memo_fact);
	cout << memo_fact[n];*/
	////////////////////////////////////////////////////////////////////////////////////////

	int n = 50, r = 3;
	cout << "Combination" << endl;
	/*cout << "Common" << endl;
	cout << "value : " << combination_common(n, r) << endl;*/
	cout << "DP" << endl;
	cout << "value : " << combination_memo_by_baek(n, r) << endl;
	cout << "visit count : " << _count << '\n' << endl;


	//int pn = n, pr = r;
	////cin >> pn >> pr;
	//int ** memo4 = new int*[pn+1];
	//for (int i = 0; i < pn+1; i++) {
	//	memo4[i] = new int[pr+1];
	//	memset(memo4[i], 0, sizeof(int)*(pr+1));
	//}
	//cout << "DP by pro" << endl;
	//cout << "value : " << combi_memo_by_pro(pn,pr,memo4) << endl;
	//cout << "visit count : " << _count2 << '\n' << endl;
	//for (int i = 0; i < pn+1; i++) delete[] memo4[i];
	//delete[] memo4;


	return 0;
}
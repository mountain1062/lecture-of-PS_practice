#include <iostream>
using namespace std;
int step_cnt, step_cnt_memo;

int step(int n) {
	cout << n << ' ';
	step_cnt++;
	if (n == 0)return 1;
	else if (n < 0)return 0;
	else return step(n - 1) + step(n - 2) + step(n - 3);
}

int step_memo(int n, int *memo) { // 하향식
	cout << n << ' ';
	step_cnt_memo++;
	if (n < 0)return 0;
	if (memo[n]) return memo[n]; // 메모리에 값이 있으면 그대로 반환
	if (n == 0)return memo[n] = 1;
	else return memo[n] = step_memo(n - 1, memo) + step_memo(n - 2, memo) + step_memo(n - 3, memo);
}

int main() {
	int n = 5;
	//일반
	cout << '\n' << "------common step result-------" << '\n';
	cout << '\n' << "visit order : ";
	int c_result = step(n);
	cout << '\n' << "visit count : " << step_cnt << '\n' << "value : " << c_result << '\n';
	//메모이제이션
	int * memo = new int[n + 1];
	memset(memo, 0, sizeof(int)*(n + 1));
	cout << '\n' << "------memo step result-------" << '\n';
	cout << '\n' << "visit order : ";
	int m_result = step_memo(n, memo);
	cout << '\n' << "visit count : " << step_cnt_memo << '\n' << "value : " << c_result << '\n';

}
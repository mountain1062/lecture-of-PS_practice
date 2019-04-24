#include <iostream>
using namespace std;
int step_cnt, step_cnt_memo, step_cnt_memo_baek;

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

void step_memo_baek(int start, int target, int *memo) { //상향식 
	cout << start << ' ';
	step_cnt_memo_baek++;

	if (memo[start]) return;
	if (start == 0 || start == 1) memo[start] = 1;
	else if (start == 2) memo[start] = memo[0] + memo[1];
	else memo[start] = memo[start - 1] + memo[start - 2] + memo[start - 3];
	for (int i = 1; i <= 3; i++) {
		if (start + i <= target) step_memo_baek(start + i, target, memo);
	}
}

int main() {
	int n = 5;
	int * memo = new int[n + 1];
	//일반
	cout << '\n' << "------common step result-------" << '\n';
	cout << '\n' << "visit order : ";
	int c_result = step(n);
	cout << '\n' << "visit count : " << step_cnt << '\n' << "value : " << c_result << '\n';
	//메모이제이션 by prof
	memset(memo, 0, sizeof(int)*(n + 1));
	cout << '\n' << "------memo step result-------" << '\n';
	cout << '\n' << "visit order : ";
	int m_result = step_memo(n, memo);
	cout << '\n' << "visit count : " << step_cnt_memo << '\n' << "value : " << m_result << '\n';
	for (int i = 0; i < n + 1; i++) cout << memo[i] << ' ';
	cout << endl;
	//메모이제이션 by baek
	memset(memo, 0, sizeof(int)*(n + 1));
	cout << '\n' << "------memo by baek step result-------" << '\n';
	cout << '\n' << "visit order : ";
	step_memo_baek(0, n, memo);
	cout << '\n' << "visit count : " << step_cnt_memo_baek << '\n' << "value : " << memo[n] << '\n';
	for (int i = 0; i < n + 1; i++) cout << memo[i] << ' ';
	cout << endl;
}
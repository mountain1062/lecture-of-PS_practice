#include <iostream>
#include <algorithm>
#include <iomanip>
#define N 5
#define I INT_MAX
using namespace std;

int fibo_cnt1, fibo_count2;

//메모이제이션+재귀을 이용한 fibo구현 (bottom-up)
void fibo_memo(int n, int *memo, int target) {
	fibo_count2++;
	memo[0] = 0; memo[1] = 1;
	if (n <= target) {
		if (n == 0 || n == 1) memo[n] = n;
		else memo[n] = memo[n - 1] + memo[n - 2];
		fibo_memo(n + 1, memo, target);
	}
}
//반복을 이용한 fibo구현 (DP)
int fibo_dp(int n, int *memo) {
	fibo_cnt1++;
	if (n == 0 || n == 1)return 1;
	memo[0] = 0; memo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo_cnt1++;
		memo[i] = memo[i - 1] + memo[i - 2];
	}
	return memo[n];
}


void floyd(int D[N][N]) {
	//k의미 확실히 기억할것 == 시험
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//둘다 무한대가 아닐 때만 업데이트 시도
				if(!(D[i][k] == I || D[k][j]==I)) 
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (D[i][j] == I)cout << setw(3) << "∞";
				else cout << setw(3) << D[i][j];
				cout << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}


//탐욕적 방법(Gridy)


//Matrix Chain Mult
//Brute Force O(n!)
//DP
int mcm(int *d) {
	int M[N + 1][N + 1];
	int K[N + 1][N + 1];
	memset(M, 0, sizeof(M));
	memset(K, 0, sizeof(M));
	for (int i = 1; i <= N; i++) M[i][i] = 0;

	//i와j의 차(곱하는 행렬의 개수)를 이용해서 반복시키면 반복순서를 올바르게 할수 있다?
	for (int len = 2; len <= N; len++) {
		for (int i = 1; i <= N - len + 1; i++) {
			int j = i + len - 1;
			M[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				int cost = M[i][k] + M[k + 1][i] + d[i - 1] * d[k] * d[j];
				if (cost < M[i][j]) {
					M[i][j] = cost;
					K[i][j] = k;
				}
				//cost = cost < M[i][j] ? M[i][j] = cost, K[i][j] = k : ;
			}
		}
	}
	return M[1][N];
}

//시험엔 안나옴
void order(int i, int j, int K[][N + 1]) {
	if (i == j) cout << 'A' << i;
	else {
		int k = K[i][j];
		cout << '(';
		order(i, k, K);
		order(k + 1, j, K);
		cout << ')';
	}
}
int mcm_2(int *d) {
	int M[N + 1][N + 1];
	int K[N + 1][N + 1];
	memset(M, 0, sizeof(M));
	memset(K, 0, sizeof(M));
	for (int i = 1; i <= N; i++) M[i][i] = 0;

	//i와j의 차(곱하는 행렬의 개수)를 이용해서 반복시키면 반복순서를 올바르게 할수 있다?
	for (int len = 2; len <= N; len++) {
		for (int i = 1; i <= N - len + 1; i++) {
			int j = i + len - 1;
			M[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				int cost = M[i][k] + M[k + 1][i] + d[i - 1] * d[k] * d[j];
				if (cost < M[i][j]) {
					M[i][j] = cost;
					K[i][j] = k;
				}
				//cost = cost < M[i][j] ? M[i][j] = cost, K[i][j] = k : ;
			}
		}
	}
	order(1, N, K);
	return M[1][N];
}

int main() {
	//fibo
	/*int n = 20;
	int *memo = new int[n];
	int *memo2 = new int[n];
	memset(memo, 0, sizeof(int)*n);
	memset(memo2, 0, sizeof(int)*n);
	fibo_memo(0, memo, 10);
	fibo_dp(10, memo2);
	for (int i = 0; i < 10; i++) cout << memo[i] << ' ';
	cout <<'\n'<< fibo_count2 << endl;
	for (int i = 0; i < 10; i++) cout << memo2[i] << ' ';
	cout << '\n' << fibo_cnt1 << endl;*/
	

	//FLOYD
	/*int W[N][N] = {
		{0,1,I,1,5},
		{9,0,3,2,I},
		{I,I,0,4,I},
		{I,I,2,0,3},
		{3,I,I,I,0}
	};
	floyd(W);*/

	//DP
	int d[N + 1] = { 5,2,3,4,6,7 };
	cout << mcm(d) << endl;

	//?
	cout << mcm_2(d) << endl;


}
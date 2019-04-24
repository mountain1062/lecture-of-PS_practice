#include <iostream>
#include <math.h>
#define N 5
using namespace std;
int COLUMN[N];

bool check(int row, int col) {
   for (int r = 0; r < row; r++) {
      int c = COLUMN[r];
      if (col == c)return false;
      //대각선 조건
      int colDistance = abs(c - col);
      int rowDistance = abs(r - row);
      if (colDistance == rowDistance) return false;
      //if (c == col - (row - r) || c == col + (row - r))return false;
   }
   return true;
}
int queen(int row) {
   if (row == N) return 1;
   int ways = 0;
   for (int col = 0; col < N; col++) {
      if (check(row, col)) {
		 COLUMN[row] = col;
         ways += queen(row + 1);
		 COLUMN[row] = 0;
      }
   }
   return ways;
}
int main() {
   cout << queen(0);
}

//#include <iostream>
//#include <math.h>
//using namespace std;
//int N, cnt;
//int Q_loc[15];
//bool promising(int r, int c) {
//	if (r == 1) return true;
//	else {
//		for (int i = 1; i < r; i++) {
//			if (c == Q_loc[i] || abs(r - i) == abs(c - Q_loc[i])) return false;
//		}
//		return true;
//	}
//}
//void put_Q(int now_row) {
//	if (now_row > N) {
//		cnt++;
//	}
//	else {
//		for (int c = 1; c <= N; c++) {
//			if (Q_loc[now_row] == 0 && promising(now_row, c) == true) {
//				Q_loc[now_row] = c;
//				put_Q(now_row + 1);
//				Q_loc[now_row] = 0;
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0), cin.tie(0);
//	cin >> N;
//	put_Q(1);
//	cout << cnt;
//}
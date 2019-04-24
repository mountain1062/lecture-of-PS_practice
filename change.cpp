#include <iostream>
using namespace std;

int nCoins = 5;
int coin[] = { 500,100,50,10,1 };
int Coin_cnt[5];
int change;
int methods_cnt;
int visit_cnt;
double cnt;

//´Ü¼ø Àç±Í by Baek;
void _change(int n) {
	if (change < 0) return;
	if (change == 0) {
		methods_cnt++;
		return;
	}
	else {
		for (int i = n; i < 5; i++) {
			if (change - coin[i] >= 0) {
				visit_cnt++;
				int temp = change;
				change -= coin[i];
				_change(i);
				change = temp;
			}
		}
	}
}

//by prof
int _change_prof(int amount, int idx) {
	if (idx == nCoins - 1)return 1;
	
	int ways = 0;
	for (int i = 0; i*coin[idx] <= amount; i++) {
		cnt++;
		int remain = amount - i * coin[idx];
		ways += _change_prof(remain, idx + 1);
	}
	return ways;
}

int main() {
	
	change = 62;
	_change(0);
	cout << methods_cnt << ' ' << visit_cnt << endl;
	cout << _change_prof(change, 0) << ' ';
	cout << cnt;
	

}
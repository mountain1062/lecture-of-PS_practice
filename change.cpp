#include <iostream>
using namespace std;

int nCoins = 5;
int coin[] = { 500,100,50,10,1 };
int Coin_cnt[5];

int change(int amount, int idx) {
	return 0;
}

int change_memo_by_pro(int n, int * memo) {
	return 0;
}

int change_meom_by_baek(int n, int target, int * memo) {
	return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 5; i++) Coin_cnt[i] = n / coin[i];
	

}
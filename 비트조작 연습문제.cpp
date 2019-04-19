/*03.28*/
#include <iostream>
using namespace std;

bool getBit(int num, int i) {
	return (num&(1<<i)) != 0; // (num&(1<<i)) != 0 이 부분이 논리 연산이기 때문에 값이 true, false로 결정된다.
}

void SecretMap(int n, int *arr1, int *arr2) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; i--) {
			if (getBit(arr1[i], j) || getBit(arr2[i], j)) cout << '#';
			else cout << ' ';
		}
		cout << '\n';
	}
}

int main() {
	int n = 5;
	//cin >> n;
	//int * arr1 = new int[n]; int * arr2 = new int[n];
	//arr1[0] = 9; arr2[1] = 20;
	int arr1[5] = { 9,20,28,18,11 };
	int arr2[5] = { 30,1,21,17,28 };
	SecretMap(n, arr1, arr2);
	return 0;

}
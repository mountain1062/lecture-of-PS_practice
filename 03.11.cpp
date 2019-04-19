/* (03.11) 동적 할당*/
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	/*동적 할당*/
	int** arr = new int*[n];
	for (int j = 0; j < n; j++) {
		arr[j] = new int[m];
		for (int k = 0; k < m; k++) {
			arr[j][k] = 0;
			//*(*(arr + j) + k) = 0;
			//*(arr + j)[k] = 0;
			//*(arr[j]+k) = 0;
			//
		}
	}
	/*할당 해제*/
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
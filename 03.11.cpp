/* (03.11) ���� �Ҵ�*/
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	/*���� �Ҵ�*/
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
	/*�Ҵ� ����*/
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
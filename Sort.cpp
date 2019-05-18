#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string.h>
using namespace std;

/*0~n-1 ���� �ߺ�����x*/
vector<int> getRandomVector(int n) {
	vector<int> vec;
	for (int i = 0; i < n; i++) vec.push_back(i);
	srand((unsigned int)time(0));
	random_shuffle(vec.begin(), vec.end());
	return vec;
}

/*0~n-1 ���� �ߺ�����o*/
vector<int> getRandomVector(int n, int k) {
	vector<int> vec;
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++) {
		vec.push_back(rand() % k);
	}
	return vec;
}

void printVector(const vector<int>& vec) { //�׳� ������ ���� => & , ���� �ǵ帮�� ���� const
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
	cout << '\n';
}

vector<int> insertionSort(const vector<int>& vec) { // 5 2 1 8 3 6 4 7
	vector<int> sorted;
	int temp;
	for (int i = 0; i < vec.size(); i++) {
		sorted.push_back(vec[i]);
		for (int j = sorted.size() - 1; j > 0 && sorted[j] < sorted[j - 1]; j--) {
			temp = sorted[j];
			sorted[j] = sorted[j - 1];
			sorted[j - 1] = temp;
		}
	}
	return sorted;
}

void quickSort(int* arr, int len) {//�Ķ����(���� ������, ���� ������)
	int p = len / 2;
	quickSort(arr, p);
	quickSort(arr + p + 1, p - 1);
}

vector<int> Counting_Sort(const vector<int>& vec,int k) {//���⵵ : O(n), k�� N���� ���� ���� ��(������ ���� ������ ������ �������� �Ҹ�)
	vector<int>sorted;
	//int* arr = new int[];//��� ���Ұ� 0���� ä��������
	vector<int> count(k);
	for (int i = 0; i < vec.size(); i++) count[vec[i]]++;
	
	for (int i = 0; i < count.size(); i++) //k(==count.size())���� �ſ� ���� ������ �ð����⵵������ ���ð� �Ǵ� ����
		for (int j = 0; j < count[i]; j++) 
			sorted.push_back(i);
	return sorted;
}


void radixSort(int* arr, int n, int d) {
	/*�Ʒ� �ΰ� ������ ���質�� ����*/
	//vector<int> bukets[10]; //���� �迭(��ü), ���ϰ� vector<int>�� �迭�̶� ����
	//vector<int> bukets(10);//�����ڿ� �Ķ���� 10�� �Ѱ��ִ� �� (�Ѱ� ���Ϳ� �������� ä���) ���ϰ� int�� �迭�̶� ����

	//������ ��������
	for (int i = 0, mod = 10, div = 1; i < d; i++, mod *= 10, div *= 10) {
		vector<int> bukets[10];
		for (int j = 0; j < n; j++) bukets[arr[j] % mod / div].push_back(arr[j]);
		for (int j = 0, size=0, k = 0; j < 10; j++, k += size) {//k�� size�� ������Ű�� ����
			if (size = bukets[j].size())
				memcpy(arr + k, bukets[j].data(), sizeof(int)*size);//vector[i].data()�� �ش� ��ġ ������ ��ȯ
			//for (int t = 0, k; t < bukets[j].size(); t++) arr[k++] = bukets[j][t]; //75��� ���� ���
		}
	}
}

int binarySearch(const vector<int>& vec, int a) { //���� Ž���� ���ĵ� ���¿����� ��밡��
	int from = 0, to = vec.size() - 1;
	int temp = -1;
	
	while (from <= to) {
		int mid = (from + to) / 2;
		if(vec[mid] > a) to = mid - 1;
		else if (vec[mid] < a) from = mid + 1;
		else return mid;
	}
	return -1;



	//���� ���� �ϴ���(�ߺ��� �� ���� �ε��� ��ȯ ���� ��)
	//while (1) {
	//	int mid = (from + to) / 2;
	//	if (mid == 0) break;
	//	if (vec[mid] == a) {
	//		temp = mid;
	//		mid--;
	//		to = mid;
	//	}
	//	else if (vec[mid] > a) to = mid;
	//	else from = mid;

	//}
	//return temp;//ã�� ���� ����.
}

int main() {
	int N = 20, K = 100;
	//vector<int> vec = getRandomVector(10);//���� 10 ���� ����
	vector<int> vec = getRandomVector(N,K);//�Ķ����(N,K)  ���� N�� ����, K�̸� ����
	vector<int> vec2 = { 10,20,30,30,40,55,66,77,88,99,100 };
	printVector(vec);
	//printVector(vec2);

	//vector<int> sorted = insertionSort(vec);
	//vector<int> sorted = Counting_Sort(vec,K);
	
	//quickSort(vec.data(),vec.size());//����.data??
	radixSort(vec.data(), vec.size(), 3);//�Ķ����(����, ���ڹ���, �ִ��ڸ���)	
	
	
	//int idx = binarySearch(vec2, 30);
	//int idx2 = binary_search(vec2.begin(), vec2.end(), 30);
	//cout << "idx num : " << idx << '\n';
	//cout << "idx2 num : " << idx2 << '\n';
	//printVector(sorted);
	printVector(vec);
	return 0;
}
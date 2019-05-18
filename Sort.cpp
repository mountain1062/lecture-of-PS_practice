#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string.h>
using namespace std;

/*0~n-1 까지 중복원소x*/
vector<int> getRandomVector(int n) {
	vector<int> vec;
	for (int i = 0; i < n; i++) vec.push_back(i);
	srand((unsigned int)time(0));
	random_shuffle(vec.begin(), vec.end());
	return vec;
}

/*0~n-1 까지 중복원소o*/
vector<int> getRandomVector(int n, int k) {
	vector<int> vec;
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++) {
		vec.push_back(rand() % k);
	}
	return vec;
}

void printVector(const vector<int>& vec) { //그냥 복사해 참조 => & , 값을 건드리지 않은 const
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

void quickSort(int* arr, int len) {//파라메터(벡터 포인터, 벡터 사이즈)
	int p = len / 2;
	quickSort(arr, p);
	quickSort(arr + p + 1, p - 1);
}

vector<int> Counting_Sort(const vector<int>& vec,int k) {//복잡도 : O(n), k는 N보다 많이 작은 수(정렬할 숫자 범위가 넓으면 넓을수록 불리)
	vector<int>sorted;
	//int* arr = new int[];//모든 원소가 0으로 채워져야함
	vector<int> count(k);
	for (int i = 0; i < vec.size(); i++) count[vec[i]]++;
	
	for (int i = 0; i < count.size(); i++) //k(==count.size())값이 매우 적기 때문에 시간복잡도에서는 무시가 되는 수준
		for (int j = 0; j < count[i]; j++) 
			sorted.push_back(i);
	return sorted;
}


void radixSort(int* arr, int n, int d) {
	/*아래 두개 차이점 시험나옴 ㄹㅇ*/
	//vector<int> bukets[10]; //백터 배열(객체), 편하게 vector<int>형 배열이라 생각
	//vector<int> bukets(10);//생성자에 파라메터 10을 넘겨주는 것 (한개 백터에 변수값을 채운것) 편하게 int형 배열이라 생각

	//손으로 돌려보기
	for (int i = 0, mod = 10, div = 1; i < d; i++, mod *= 10, div *= 10) {
		vector<int> bukets[10];
		for (int j = 0; j < n; j++) bukets[arr[j] % mod / div].push_back(arr[j]);
		for (int j = 0, size=0, k = 0; j < 10; j++, k += size) {//k는 size를 누적시키는 변수
			if (size = bukets[j].size())
				memcpy(arr + k, bukets[j].data(), sizeof(int)*size);//vector[i].data()는 해당 위치 포인터 반환
			//for (int t = 0, k; t < bukets[j].size(); t++) arr[k++] = bukets[j][t]; //75행과 같은 기능
		}
	}
}

int binarySearch(const vector<int>& vec, int a) { //이진 탐색은 정렬된 상태에서만 사용가능
	int from = 0, to = vec.size() - 1;
	int temp = -1;
	
	while (from <= to) {
		int mid = (from + to) / 2;
		if(vec[mid] > a) to = mid - 1;
		else if (vec[mid] < a) from = mid + 1;
		else return mid;
	}
	return -1;



	//내가 구현 하던거(중복시 더 앞의 인덱스 반환 구현 중)
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
	//return temp;//찾는 값이 없다.
}

int main() {
	int N = 20, K = 100;
	//vector<int> vec = getRandomVector(10);//길이 10 랜덤 백터
	vector<int> vec = getRandomVector(N,K);//파라메터(N,K)  숫자 N개 랜덤, K미만 백터
	vector<int> vec2 = { 10,20,30,30,40,55,66,77,88,99,100 };
	printVector(vec);
	//printVector(vec2);

	//vector<int> sorted = insertionSort(vec);
	//vector<int> sorted = Counting_Sort(vec,K);
	
	//quickSort(vec.data(),vec.size());//벡터.data??
	radixSort(vec.data(), vec.size(), 3);//파라메터(벡터, 숫자범위, 최대자리수)	
	
	
	//int idx = binarySearch(vec2, 30);
	//int idx2 = binary_search(vec2.begin(), vec2.end(), 30);
	//cout << "idx num : " << idx << '\n';
	//cout << "idx2 num : " << idx2 << '\n';
	//printVector(sorted);
	printVector(vec);
	return 0;
}
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <ctime>
#define DIM 16 //몇 차원
#define N 1000 //점 개수
using namespace std;

vector<double> getrandomVector(int d) {
	vector<double> vec;
	for (int i = 0; i < d; i++) {
		vec.push_back(rand() / (double)RAND_MAX);
	}
	return vec;
}

//브루트포스
int bf_nnSearch(const vector< vector<double> >&data, const vector<double>&query) {
	int n = N, d = DIM;
	double best_dist = DBL_MAX; int best_idx;//현재까지 제일 가까운 거리와 인덱스 저장
	for (int i = 0; i < n; i++) {
		double dist = 0; //x,y,z.....거리 누적?
		for (int j = 0; j < d; j++) {
			//i번쨰 파란색 점의 j차원의 값, 빨간색 점의 j차원의 값
			dist += (data[i][j] - query[j])*(data[i][j] - query[j]);
		}
		if (dist < best_dist) {
			best_dist = dist; 
			best_idx = i;
		}
	}
	return best_idx;

	
}


//K차원 트리로 구현 (과제)

int main() {
	srand(unsigned(time(0)));
	vector< vector<double> >data;
	for (int i = 0; i < N; i++) {
		data.push_back(getrandomVector(DIM));
	}
	vector<double>query = getrandomVector(DIM);
	
	//시간 체크
	clock_t start = clock();
	int idx = bf_nnSearch(data, query);
	cout << idx << '\n';
	clock_t end = clock();
	double time = double(end - start) / CLOCKS_PER_SEC;
	cout << time << '\n';

	
}
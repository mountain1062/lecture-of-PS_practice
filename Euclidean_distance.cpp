#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <ctime>
#define DIM 16 //�� ����
#define N 1000 //�� ����
using namespace std;

vector<double> getrandomVector(int d) {
	vector<double> vec;
	for (int i = 0; i < d; i++) {
		vec.push_back(rand() / (double)RAND_MAX);
	}
	return vec;
}

//���Ʈ����
int bf_nnSearch(const vector< vector<double> >&data, const vector<double>&query) {
	int n = N, d = DIM;
	double best_dist = DBL_MAX; int best_idx;//������� ���� ����� �Ÿ��� �ε��� ����
	for (int i = 0; i < n; i++) {
		double dist = 0; //x,y,z.....�Ÿ� ����?
		for (int j = 0; j < d; j++) {
			//i���� �Ķ��� ���� j������ ��, ������ ���� j������ ��
			dist += (data[i][j] - query[j])*(data[i][j] - query[j]);
		}
		if (dist < best_dist) {
			best_dist = dist; 
			best_idx = i;
		}
	}
	return best_idx;

	
}


//K���� Ʈ���� ���� (����)

int main() {
	srand(unsigned(time(0)));
	vector< vector<double> >data;
	for (int i = 0; i < N; i++) {
		data.push_back(getrandomVector(DIM));
	}
	vector<double>query = getrandomVector(DIM);
	
	//�ð� üũ
	clock_t start = clock();
	int idx = bf_nnSearch(data, query);
	cout << idx << '\n';
	clock_t end = clock();
	double time = double(end - start) / CLOCKS_PER_SEC;
	cout << time << '\n';

	
}
#include<iostream>
using namespace std;

int fibo_count = 0, fibo_baek_count2 = 0, fibo_prof_count3 = 0;
int comb_count, comb_baek_count, comb_prof_count;
int fact_cnt;
//����Լ��� �ٽ� �ʱ��� �� ���ϰ� ������ ���� ���踦 ���Ѵ�. x^0�� 1 
//double power(double x, int n)
//{
//	if (n == 0) return 1.0;
//	power(x, n - 1) * x;
//}

int factorial(int n)//->n!
{
	if (n == 1) return 1;
	return n * (factorial(n - 1));
}

void factorial_memo(int n, int target, int*memo) {
	fact_cnt++;
	if (n == 1) {
		memo[1] = 1;
		factorial_memo(n + 1, target, memo);
	}
	if (1 < n&&n <= target) {
		memo[n] = n * memo[n - 1];
		factorial_memo(n + 1, target, memo);
	}
}

int fibo(int n)
{
	//��ȿ���� --> �ð� ��
	fibo_count++;
	if (n == 0) return 0;
	if (n == 1)return 1;
	return fibo(n - 1) + fibo(n - 2);
}

//�޸������̼��� �̿��� fibo���� ( DP )
void fibo_memo(int n, int *memo, int target) {
	fibo_baek_count2++;
	memo[0] = 0; memo[1] = 1;
	if (n <= target) {
		if (n == 0 || n == 1) memo[n] = n;
		else memo[n] = memo[n - 1] + memo[n - 2];
		fibo_memo(n + 1, memo, target);
	}
}

//�޸������̼��� �̿��� fibo���� by ������
int fibo_memo_prof(int n, int* memo) {
	fibo_prof_count3++;
	if (memo[n]) return memo[n]; //�޸�Ǿ� ������ ����
	if (n == 0 || n == 1) {
		return memo[n] = n;
	}
	/*memo[n] = fibo_memo_pro(n - 1,memo) + fibo_memo_pro(n - 2,memo);
	return memo[n];*/
	//�� ������ �ٿ��� �Ʒ�ó�� ���� ���� (�򰡰� ��¼��)
	return memo[n] = fibo_memo_prof(n - 1, memo) + fibo_memo_prof(n - 2, memo);
}

int combination_common(int n, int r) {
	comb_count++;
	if (r == 0 || r == n) return 1;
	return combination_common(n - 1, r) + combination_common(n - 1, r - 1);
}

int combination_memo_by_baek(int n, int r) {
	comb_baek_count++;
	int *memo_factoral;
	memo_factoral = new int[n + 1];
	memset(memo_factoral, 0, sizeof(int)*(n + 1));
	factorial_memo(1, n, memo_factoral);
	int result = memo_factoral[n] / (memo_factoral[r] * memo_factoral[n - r]);
	return result;
}

int combi_memo_by_prof(int n, int r, int** memo) {
	comb_prof_count++;
	if (memo[n][r])return memo[n][r];
	if (r == 0 || n == r) return memo[n][r] = 1;
	return combi_memo_by_prof(n - 1, r - 1, memo) + combi_memo_by_prof(n - 1, r, memo);
}

int main()
{
	//int n = 10;
	////�Ϲ��� fibo
	//cout << "common_fibo" << endl;
	//cout << "value : " << fibo(n) << endl;
	//cout << "visit count : " << fibo_count << '\n' << endl;

	////�޸������̼��� �̿��� fibo
	//int* memo;//���� ���� ������ �迭
	//memo = new int[n + 1];
	//memset(memo, 0, sizeof(int)*(n + 1));
	//fibo_memo(0, memo, n);
	//cout << "DP fibo by baek" << endl;
	//cout << "value : " << memo[n] << endl;
	//cout <<"visit count : "<< fibo_baek_count2 <<'\n'<< endl;

	//int* memo2;
	//memo2 = new int[n + 1];
	//memset(memo2, 0, sizeof(int)*(n + 1));
	//cout << "DP fibo by prof" << endl;
	//cout <<"value : "<< fibo_memo_prof(n, memo2) << endl;
	//cout << "visit count : " << fibo_prof_count3 << '\n' << endl;

	int n = 5, r = 3;
	cout << "Combination" << endl;
	cout << "Common" << endl;
	cout << "value : " << combination_common(n, r) << endl;
	cout << "visit count : " << comb_count << '\n' << endl;

	cout << "DP by Baek" << endl;
	cout << "value : " << combination_memo_by_baek(n, r) << endl;
	cout << "visit count : " << comb_baek_count+fact_cnt << '\n' << endl;


	int pn = n, pr = r;
	//cin >> pn >> pr;
	int ** memo4 = new int*[pn+1];
	for (int i = 0; i < pn+1; i++) {
		memo4[i] = new int[pr+1];
		memset(memo4[i], 0, sizeof(int)*(pr+1));
	}
	cout << "DP by pro" << endl;
	cout << "value : " << combi_memo_by_prof(pn,pr,memo4) << endl;
	cout << "visit count : " << comb_prof_count << '\n' << endl;
	for (int i = 0; i < pn+1; i++) delete[] memo4[i];
	delete[] memo4;


	return 0;
}
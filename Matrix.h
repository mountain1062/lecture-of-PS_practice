#pragma once
#include <iostream>

class Matrix {
	int row, col;
	//ȣ���� ������ ������ ������ �������� ������ class���� �ɹ� ������ ������ �־���Ѵ�.
	int** data;//������ ������(2���� �迭�� ���� ������)
	//Matrix();//�⺻ ������
public: //���� �Լ��� public, ������ private
	Matrix(int row, int cal);//���� �� ���� �Է� �޴� ������

	//�Ҹ����� �뵵�� 99�� �����Ҵ��� ���� ���ֱ� ���� ��
	//���� �Ҵ��� ������ ���� �Ҹ��ڸ� ������ �ʾƵ� �ȴ�?
	~Matrix(void);//�Ҹ���

	void doPrint();
	int getElement(int row, int col) {
		return data[row - 1][col - 1];
	}
	void setElement(int row, int col, int val) {
		data[row - 1][col - 1] = val;
	}
	void doTranspose(void);
	
	//������ �Լ� ��, �������� �ǿ�����
	bool operator==(const Matrix& rhs);//rhs : right hands side
	Matrix operator*(const Matrix& rhs);

	//Matrix multi(Matrix a);
};

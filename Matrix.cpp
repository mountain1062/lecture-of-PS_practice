#include "Matrix.h"

Matrix::Matrix(int row, int col) {
	this->row = row;//�ɹ����� -> �Ķ����
	this->col = col;
	
	//2���� �迭 �����Ҵ�
	data = new int*[row];
	for (int r = 0; r < row; r++) {
		data[r] = new int[col];
		for (int c = 0; c < col; c++) {
			data[r][c] = r * col + c + 1;
		}
	}
}

//Matrix::~Matrix(void) {
//	//�����ڿ��� ���������� 2���� �迭�� ����
//	//2���� �����迭 ������ ���ʺ��� ���� ����
//
//	for (int r = 0; r < row; r++) {
//		delete[] data[r];
//	}
//	delete[] data;
//}

void Matrix::doPrint(void) {
	for (int r = 0; r < row; r++) {
		std::cout << "[ ";
		for (int c = 0; c < col; c++) {
			std::cout << data[r][c] << ' ';
		}
		std::cout <<']'<<std::endl;
	}
}

void Matrix::doTranspose(void) {
	//int** temp = data;//���� ���� �Ҵ� ���� �������� �޸𸮰� ���� �����Ƿ� �����͸� ��� ���ָ� �ȴ�.
	//���� �Ҵ�
	int** new_data = new int*[col];
	for (int r = 0; r < col; r++) {
		new_data[r] = new int[row];
		for (int c = 0; c < row; c++) {
			new_data[r][c] = data[c][r];
		}
	}
	//������ �ִ� �޸� ����
	for (int r = 0; r < row; r++) {
		delete[] data[r];
	}
	delete[] data;


	/*
	int** data = new int*[col];
	for (int r = 0; r < col; r++) {
		data[r] = new int[row];
		for (int c = 0; c < row; c++) {
			data[r][c] = this->data[c][r];
		}
	}
	//������ �ִ� �޸� ����
	for (int r = 0; r < row; r++) {
		delete[] this->data[r];
	}
	delete[] this->data;
	*/


	//��� ����
	int temp = row;	row = col;	col = temp;
	//���ο� �迭�� ������ ����
	data = new_data;
}

bool Matrix::operator==(const Matrix& rhs) {//rhs : right hands side
	if (this->row != rhs.row || this->col != rhs.col) return false;
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			if (this->data[r][c] != rhs.data[r][c]) return false;
	return true;
}

Matrix Matrix::operator*(const Matrix& rhs) {
	Matrix res(this->row, rhs.col); // ����� �����ϴ� ���
	//this->r,c : ������ �� ���
	//rhs : ������ �� ���
	for (int r = 0; r < this->row; r++) {
		for (int c = 0; c < rhs.col; c++) {
			for (int k = 0; k < rhs.row; k++) {
				res.data[r][c] += data[r][k] * rhs.data[k][c];
			}
		}
	}
	return res;
}
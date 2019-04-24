#include "Matrix.h"

Matrix::Matrix(int row, int col) {
	this->row = row;//맴버변수 -> 파라메터
	this->col = col;
	
	//2차원 배열 동적할당
	data = new int*[row];
	for (int r = 0; r < row; r++) {
		data[r] = new int[col];
		for (int c = 0; c < col; c++) {
			data[r][c] = r * col + c + 1;
		}
	}
}

//Matrix::~Matrix(void) {
//	//생성자에서 동적생성한 2차원 배열을 해제
//	//2차원 동적배열 해제시 안쪽부터 먼저 해제
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
	//int** temp = data;//기존 동적 할당 해제 전까지는 메모리가 남아 있으므로 포인터만 백업 해주면 된다.
	//새로 할당
	int** new_data = new int*[col];
	for (int r = 0; r < col; r++) {
		new_data[r] = new int[row];
		for (int c = 0; c < row; c++) {
			new_data[r][c] = data[c][r];
		}
	}
	//기존에 있던 메모리 해제
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
	//기존에 있던 메모리 해제
	for (int r = 0; r < row; r++) {
		delete[] this->data[r];
	}
	delete[] this->data;
	*/


	//행렬 스왑
	int temp = row;	row = col;	col = temp;
	//새로운 배열을 뒤집어 씌움
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
	Matrix res(this->row, rhs.col); // 결과를 저장하는 행렬
	//this->r,c : 연산자 앞 행렬
	//rhs : 연산자 뒤 행렬
	for (int r = 0; r < this->row; r++) {
		for (int c = 0; c < rhs.col; c++) {
			for (int k = 0; k < rhs.row; k++) {
				res.data[r][c] += data[r][k] * rhs.data[k][c];
			}
		}
	}
	return res;
}
#pragma once
#include <iostream>

class Matrix {
	int row, col;
	//호출이 끝나면 포인터 변수가 없어지기 떄문에 class에서 맴버 변수로 가지고 있어야한다.
	int** data;//데이터 포인터(2차원 배열에 대한 포인터)
	//Matrix();//기본 생성자
public: //보통 함수는 public, 변수는 private
	Matrix(int row, int cal);//정수 두 개를 입력 받는 생성자

	//소멸자의 용도는 99퍼 동적할당을 해제 해주기 위한 것
	//동적 할당이 없으면 굳이 소멸자를 만들지 않아도 된다?
	~Matrix(void);//소멸자

	void doPrint();
	int getElement(int row, int col) {
		return data[row - 1][col - 1];
	}
	void setElement(int row, int col, int val) {
		data[row - 1][col - 1] = val;
	}
	void doTranspose(void);
	
	//왼쪽이 함수 콜, 오른쪽이 피연산자
	bool operator==(const Matrix& rhs);//rhs : right hands side
	Matrix operator*(const Matrix& rhs);

	//Matrix multi(Matrix a);
};

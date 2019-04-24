#include <iostream>
#define LEN 8
#define T 16
#define BYTE T/LEN
using namespace std;
unsigned char readBinary(const char *Bitstring) {
	unsigned num = 0; // 00000000
	for (int i = 0; i < LEN; i++) {
		num = num << 1;
		//num += Bitstring[i] - '0';
		if (Bitstring[i] == '1') num += 1;
	}
	return num;
}

bool getBit(unsigned char num, int i) { //i번 자리 비트를 얻어내는 함수
	unsigned mask = 1 << i;
	if ((num & mask) == 0) return false; // num&mask 연산시 괄호 필수
	else return true;
}

void printBit(unsigned char num) { //10진수 숫자를 bit형식으로 출력
	for (int i = LEN; i > 0; i--) {
		cout<<getBit(num, i - 1);
	}
	cout << endl;
}

unsigned char setBiton(unsigned char num, int i) {
	return (num | (1 << i));
}

unsigned char setBitoff(unsigned char num, int i) {
	return (num & ~(1 << i));
}

unsigned char getReverseBits(unsigned char num) {
	unsigned char num2 = 0;
	for (int i = 0; i < LEN; i++) {
		num2 = num2 << 1;
		num2 += getBit(num, i);
	}
	return num2;
}

int getHammingDistance(unsigned char *a, unsigned char * b) {
	//단순 반복
	int cnt = 0;
	 for (int i = 0; i < BYTE; i++) {
	 	for (int j = 0; j < LEN; j++) {
	 		if (getBit(a[i], j) != getBit(b[i], j))cnt++;
	 	}
	 }

	//다른방법1
	//for (int i = 0; i < BYTE; i++) {
	//	//비트조작 pdf page 11 확인
	//	for (unsigned char c = a[0] ^ b[0]; c != 0; c = c & (c - 1))cnt++;
	//	//"11111110"(254) --> "11111100" --> "11111000" -->.....-->"00000000" 
	//}
	return cnt;
}

int main() {
	/*cout << (int)readBinary("10010101") << endl;
	cout << readBinary("10010101") << endl;*/

	//cout << getBit(170, 2) << endl;//170 : 10101010 //1
	//cout << getBit(170, 0) << endl;//0

	//printBit(getReverseBits(readBinary("11110000")));
	
	unsigned char a[BYTE], b[BYTE];
	a[0] = readBinary("11111111"); a[1] = readBinary("10000000");
	b[0] = readBinary("00000001"); b[1] = readBinary("00000000");
	cout << getHammingDistance(a, b) << endl;//8
}
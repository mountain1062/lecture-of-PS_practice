/*03.21*/
#include <iostream>
#define LEN 8
#define T 16
#define BYTE T/LEN
using namespace std;

unsigned char readBinary(const char * bitString) {
	unsigned char num = 0;
	//bitString[0] = 0 or 1
	for (int i = 0; i < LEN; i++) {
		num = num << 1;
		num += bitString[i] - '0';
		//if (bitString[i] == '1') num += 1;/// ���� ���� ����
	}
	return num;
}
bool getBit(unsigned char num, int i) {
	unsigned char mask = 1 << i;
	if ((num & mask) == 0) return false;
	else return true;
	/*
	���� 3�ٰ� ���� �ǹ�
	return (num&(1<<i)) != 0; // (num&(1<<i)) != 0 �� �κ��� �� �����̱� ������ ���� true, false�� �����ȴ�.
	*/
}
void printBit(unsigned char num) {
	for (int i = LEN - 1; i >= 0; i--) cout << getBit(num, i);
	cout << '\n';
}

unsigned char setBitOn(unsigned char num, int i) {
	/*unsigned char mask = 1 << i;
	num = num | mask;
	return num;*/
	return (num | (1 << i));
}
unsigned char setBitOff(unsigned char num, int i) {
	/*unsigned char mask = 1 << i;
	mask = ~mask;
	num = num & mask;
	return num;*/
	return (num & ~(1 << i));
}
unsigned char updateBit(unsigned char num, int i, bool flag) {
	if (flag == 1) return setBitOn(num, i);
	else return setBitOff(num, i);
}

unsigned char getReverseBits(unsigned char num) {
	unsigned char num2 = 0;
	for (int i = 0; i < LEN; i++) {
		num2 = num2 << 1;
		num2 += getBit(num, i);
	}
	return num2;
}

bool isSymmerty(unsigned num) {
	/*�ܼ� ��
	for (int i = 0; i < LEN/2; i++) {
		if (getBit(num, i) != getBit(num, LEN - i - 1)) return 0;
	}
	return 1;
	*/
	//�ø�Ʈ��? �̿� (������ �е� �ڷ� �е� ������ �̿�)
	return num == getReversedBits(num);
}
int getHammingDistance(unsigned char *a, unsigned char * b) {
	//�ܼ� �ݺ�
	int cnt = 0;
	for (int i = 0; i < BYTE; i++) {
		for (int j = 0; j < LEN; j++) {
			if (getBit(a[i], j) != getBit(b[i], j))cnt++;
		}
	}

	//�ٸ����1
	for (int i = 0; i < BYTE; i++) {
		//��Ʈ���� pdf page 11 Ȯ��
		for (unsigned char c = a[0] ^ b[0]; c != 0; c = c & (c - 1))cnt++;
		//"11111110"(254) --> "11111100" --> "11111000" -->.....-->"00000000" 
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	
	//���ڿ� ������ 2���� �б�
	//cout << (int)readBinary("00000000") << '\n'; //0
	//cout << (int)readBinary("11111111") << '\n'; //255
	cout << (int)readBinary("01010101") << '\n'; //85
	cout << (int)readBinary("10000001") << '\n'; //129
	
	///*
	//��Ʈ �� ���
	//cout << getBit(readBinary("10000001"), 7) << endl;//1
	//cout << getBit(readBinary("10000001"), 6) << endl;//0
	//printBit(readBinary("10000000")); //10000000
	//printBit(readBinary("01010101")); //01010101
	//*/
	///*Ư�� ��ġ ��Ʈ �� ����
	//printBit(setBitOn(readBinary("00000000"), 7));
	//printBit(setBitOff(readBinary("00000000"), 7));
	//printBit(updateBit(readBinary("10000000"), 0, true));
	//*/
	///*��Ʈ�� ������
	//printBit(getReversedBits(readBinary("11010101")));
	//*/
	///*��忭�� �¿� ��Ī ����
	//cout << isSymmerty(readBinary("01011010")) << endl; // 1
	//cout << isSymmerty(readBinary("10101010")) << endl; // 0
	//*/
	///*�عְŸ�*/
	//unsigned char a[BYTE], b[BYTE];
	//a[0] = readBinary("11111111"); a[1] = readBinary("10000000");
	//b[0] = readBinary("00000001"); b[1] = readBinary("00000000");
	//cout << getHammingDistance(a, b) << endl;//8
}

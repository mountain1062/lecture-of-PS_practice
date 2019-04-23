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
		//if (bitString[i] == '1') num += 1;/// 위와 같은 문장
	}
	return num;
}
bool getBit(unsigned char num, int i) {
	unsigned char mask = 1 << i;
	if ((num & mask) == 0) return false;
	else return true;
	/*
	위의 3줄과 같은 의미
	return (num&(1<<i)) != 0; // (num&(1<<i)) != 0 이 부분이 논리 연산이기 때문에 값이 true, false로 결정된다.
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
	/*단순 비교
	for (int i = 0; i < LEN/2; i++) {
		if (getBit(num, i) != getBit(num, LEN - i - 1)) return 0;
	}
	return 1;
	*/
	//시메트리? 이용 (앞으로 읽든 뒤로 읽든 같음을 이용)
	return num == getReversedBits(num);
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
	for (int i = 0; i < BYTE; i++) {
		//비트조작 pdf page 11 확인
		for (unsigned char c = a[0] ^ b[0]; c != 0; c = c & (c - 1))cnt++;
		//"11111110"(254) --> "11111100" --> "11111000" -->.....-->"00000000" 
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	
	//문자열 형대의 2진수 읽기
	//cout << (int)readBinary("00000000") << '\n'; //0
	//cout << (int)readBinary("11111111") << '\n'; //255
	cout << (int)readBinary("01010101") << '\n'; //85
	cout << (int)readBinary("10000001") << '\n'; //129
	
	///*
	//비트 값 출력
	//cout << getBit(readBinary("10000001"), 7) << endl;//1
	//cout << getBit(readBinary("10000001"), 6) << endl;//0
	//printBit(readBinary("10000000")); //10000000
	//printBit(readBinary("01010101")); //01010101
	//*/
	///*특정 위치 비트 값 조작
	//printBit(setBitOn(readBinary("00000000"), 7));
	//printBit(setBitOff(readBinary("00000000"), 7));
	//printBit(updateBit(readBinary("10000000"), 0, true));
	//*/
	///*비트열 뒤집기
	//printBit(getReversedBits(readBinary("11010101")));
	//*/
	///*비드열의 좌우 대칭 여부
	//cout << isSymmerty(readBinary("01011010")) << endl; // 1
	//cout << isSymmerty(readBinary("10101010")) << endl; // 0
	//*/
	///*해밍거리*/
	//unsigned char a[BYTE], b[BYTE];
	//a[0] = readBinary("11111111"); a[1] = readBinary("10000000");
	//b[0] = readBinary("00000001"); b[1] = readBinary("00000000");
	//cout << getHammingDistance(a, b) << endl;//8
}

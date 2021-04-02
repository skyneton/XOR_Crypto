#include <iostream>
using namespace std;
#define endl '\n'

void defaultKey(int *key, int SIZE) {
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		*(key + i) = rand() % 10;
	}
}

void printMenu() {
	cout << "1. 암호화/복호화" << endl;
	cout << "2. 키 변경" << endl;
	cout << "입력: ";
}

void crypto(int *key, int SIZE) {
	char arr[100];
	cout << "문자열 입력: ";
	cin >> arr;
	cout << "결과: ";
	for (int i = 0; i < strlen(arr); i++) {
		cout << (char) (arr[i] ^ *(key + i % SIZE));
	}
	cout << endl << endl;
}

void keyChange(int* key, int* SIZE) {
	free(key);
	char arr[100];
	cout << "문자열 입력: ";
	cin >> arr;
	*SIZE = strlen(arr);
	key = (int*)malloc(sizeof(int) * *SIZE);
	for (int i = 0; i < strlen(arr); i++) {
		int tmp = (int) arr[i];
		if (arr[i] >= '0' && arr[i] <= '9') tmp -= '0';
		*(key + i) = tmp;
	}
	cout << "키가 변경되었습니다." << endl << endl;
}

int main() {
	int SIZE = 5;
	int* key = (int*)malloc(sizeof(int) * SIZE);
	defaultKey(key, SIZE);
	while (1) {
		int type;
		printMenu();
		cin >> type;
		if (!(type >= 1 && type <= 2)) break;
		switch (type) {
			case 1: {
				crypto(key, SIZE);
				break;
			}
			case 2: {
				keyChange(key, &SIZE);
				break;
			}
		}
	}
	free(key);
}
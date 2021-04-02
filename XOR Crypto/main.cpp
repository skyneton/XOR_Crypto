#include <iostream>
using namespace std;
#define endl '\n'
#define SAFE_FREE(a) if(a) {free(a); a=NULL;}

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
	char arr[101];
	cout << "문자열 입력: ";
	cin.ignore(); //입력버퍼 초기화
	cin.getline(arr, 100);
	cout << "결과: ";
	for (int i = 0; i < strlen(arr); i++) {
		cout << (char) (arr[i] ^ *(key + i % SIZE));
	}
	cout << endl << endl;
}

int* keyChange(int* key, int* SIZE) {
	SAFE_FREE(key);
	char arr[101];
	cout << "문자열 입력: ";
	cin.ignore(); //입력버퍼 초기화
	cin.getline(arr, 100);
	*SIZE = strlen(arr);
	key = (int*)malloc(sizeof(int) * *SIZE);
	for (int i = 0; i < strlen(arr); i++) {
		int tmp = (int) arr[i];
		if (arr[i] >= '0' && arr[i] <= '9') tmp -= '0';
		*(key + i) = tmp;
	}
	cout << "키가 변경되었습니다." << endl << endl;
	return key;
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
				key = keyChange(key, &SIZE);
				break;
			}
		}
	}
	SAFE_FREE(key);
}
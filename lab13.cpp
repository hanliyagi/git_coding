#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;

	cout << "홀수 숫자를 하나 입력해 주세요 : ";
	cin >> num;

	int** arr = new int*[num];
	for (int i = 0; i < num; i++) {
		arr[i] = new int[num];
		for (int j = 0; j < num; j++)
			arr[i][j] = 0;
	}
	
	int count = 0;
	while (count < num * num) {
		for (int i = 0; i < num; i++) {

		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < num; i++) {
		delete arr[i];
	}
	delete[] arr;

	return 0;
}

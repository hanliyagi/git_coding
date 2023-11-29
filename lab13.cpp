#include <iostream>
#include <iomanip>
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
	
	int row = 0, col = num / 2, count = 1;
	while (count <= num * num) {
		if (arr[row][col] != 0) {
			row += 2;
			col -= 1;
			if (row >= num)
				row -= num;
			if (col < 0)
				col = num - 1;
			arr[row][col] = count;
			count++;
		}
		else {
			arr[row][col] = count;
			count++;
		}
		row--;
		col++;
		if (row < 0)
			row = num - 1;
		if (col >= num)
			col = 0;
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << setw(4) << arr[i][j] ;
		}
		cout << endl;
	}

	for (int i = 0; i < num; i++) {
		delete arr[i];
	}
	delete[] arr;

	return 0;
}

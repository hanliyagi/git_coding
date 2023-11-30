#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(const string& fname) :
		message("File \"" + fname + "\" not found") {}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

vector<vector<int>> read_file(string& fname) {
	ifstream fin(fname);
	vector<vector<int>> v(10, vector<int>(10));
	if (!fin) {
		throw FileNotFoundException(fname);
	}
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				fin >> v.at(i).at(j);
			}
		}
	}
	return v;
}
int main()
{
	ofstream ofs;
	ofs.open("temp.txt");
	// 임의의 10x10 행렬 저장 구현
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ofs << rand() % 101 << " ";
		}
		ofs << endl;
	}
	ofs.close();

	// 파일이름 입력tme
	// 입력받은 파일이름에 맞는 파일을 읽어와 vector로 입력 후, 출력 구현
	string str;
	cout << "파일 이름 : ";
	cin >> str;
	try {
		vector<vector<int>> vec = read_file(str);
		int row, col;
		cout << "출력할 행 크기 : ";
		cin >> row;
		cout << "출력할 열 크기 : ";
		cin >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << vec.at(i).at(j) << " ";
			}
			cout << endl;
		}
	}
	catch (exception& e) {
		cout << "\n" << e.what() << "\n";
	}

	return 0;
}

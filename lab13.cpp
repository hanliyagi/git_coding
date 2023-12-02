#include <iostream>
#include <string>
using namespace std;

int main()
{
	string wrd, reversed_wrd;
	bool flag = false;

	auto f = [](string str1, string str2) {
		if(str1==str2)
			cout << "이 문자는 회문입니다." << endl << endl;
		else
			cout << "이 문자는 회문이 아닙니다." << endl << endl;
		};

	while (!flag) {
		cout << "문자열 하나를 입력해주세요 : ";
		cin >> wrd;
		if (wrd == "q" || wrd == "Q")
			flag = true;
		else {
			reversed_wrd = wrd;
			int len = wrd.length();

			for (int i = 0; i < len; i++)
				reversed_wrd.at(i) = wrd.at(len - i - 1);

			cout << "입력하신 문자열의 역순 : " << reversed_wrd << endl;
			f(wrd, reversed_wrd);
		}
	}

	return 0;
}

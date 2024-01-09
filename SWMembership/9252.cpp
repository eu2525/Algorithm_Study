#include <iostream>
#include <string>
using namespace std;

int map[1002][1002] = { 0 };

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	//map을 채우는 코드
	for (int i = 0; i < str1.size(); i++) {
		char s = str1[i];
		for (int j = 0; j < str2.size(); j++) {
			if (s == str2[j]) {
				map[i + 1][j + 1] = map[i][j] + 1;
			}
			else {
				map[i + 1][j + 1] = max(map[i][j + 1], map[i + 1][j]);
			}
		}
	}
	string str = "";
	int cnt = 0;
	//search하는 과정의 코드
	int row = str1.size();
	int col = str2.size();
	while (map[row][col] != 0) {
		if (map[row][col] == map[row - 1][col]) {
			row = row - 1;
		}
		else if (map[row][col] == map[row][col - 1]) {
			col = col - 1;
		}
		else {
			str += str1[row - 1];
			cnt += 1;
			row -= 1;
			col -= 1;
		}
	}
	cout << cnt << '\n';
	for (int i = str.size() - 1; i >= 0; i--) {
		cout << str[i];
	}
}

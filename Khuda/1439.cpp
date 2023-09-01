#include <iostream>
#include <string>;
using namespace std;

int main() {
	string s;
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[i+1]) {
			cnt += 1;
		}
	}

	string a = "1234";
	
	cout << a[4] << '\n';

	cout << cnt / 2 << '\n';
}
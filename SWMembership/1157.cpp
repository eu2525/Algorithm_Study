#include <iostream>
#include <string>
using namespace std;

int cnt[27] = { 0 };

int main() {
	string noun;
	cin >> noun;
	for (int i = 0; i < noun.size(); i++) {
		char a = noun[i];
		if (a >= 'a' && a <= 'z') {
			int a_num = a - 'a';
			cnt[a_num] += 1;
		}
		else if (a >= 'A' && a <= 'Z') {
			int b_num = a - 'A';
			cnt[b_num] += 1;
		}
	}
	int max_num = 0;
	int max_idx = 0;
	bool same_num = false;
	for (int i = 0; i < 27; i++) {
		if (max_num < cnt[i]) {
			max_num = cnt[i];
			max_idx = i;
			same_num = false;
		}
		else if (max_num == cnt[i]) {
			same_num = true;
		}
	}

	if (same_num == true) {
		cout << "?" << '\n';
	}
	else {
		cout << char('A' + max_idx) << '\n';
	}
}

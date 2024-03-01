#include <iostream>
#include <vector>
using namespace std;

int plus_num, minus_num, mul_num, div_num;
int max_num = -1000000000;
int min_num = 1000000000;
vector<int> num;


void dfs(int idx, int val) {
	if (idx == num.size()) {
		max_num = max(max_num, val);
		min_num = min(min_num, val);
	}
	else {
		if (plus_num > 0) {
			int new_val = val + num[idx];
			plus_num -= 1;
			dfs(idx + 1, new_val);
			plus_num += 1;
		}
		if (minus_num > 0) {
			int new_val = val - num[idx];
			minus_num -= 1;
			dfs(idx + 1, new_val);
			minus_num += 1;
		}	
		if (mul_num > 0) {
			int new_val = val * num[idx];
			mul_num -= 1;
			dfs(idx + 1, new_val);
			mul_num += 1;
		}
		if (div_num > 0) {
			int new_val = val / num[idx];
			div_num -= 1;
			dfs(idx + 1, new_val);
			div_num += 1;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}
	
	cin >> plus_num >> minus_num >> mul_num >> div_num;

	dfs(1, num[0]);

	cout << max_num << '\n';
	cout << min_num << '\n';
}

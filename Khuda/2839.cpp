#include <iostream>
using namespace std;

int N;
int result = 5000;

void dfs(int cnt) {
	if (cnt < 0) {
		return;
	}
	else {
		int sum = N - 5 * cnt;
		if (sum % 3 == 0) {
			int count = cnt + (sum / 3);
			result = min(result, count);
			dfs(cnt - 1);
		}
		else {
			dfs(cnt - 1);
		}
	}
}

int main() {
	cin >> N;
	int start = N / 5;

	dfs(start);

	if (result == 5000) 
		cout << "-1" << '\n';
	else 
		cout << result << '\n';

}

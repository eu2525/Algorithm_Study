#include <iostream>
#include <vector>
using namespace std;

int M, N;
bool num[10] = { false };

void dfs(int start, int cnt) {
	if (cnt == N) {
		for (int i = 1; i < 10; i++) {
			if (num[i] == true) {
				cout << i << " ";
			}
		}
		cout << '\n';
	}
	else {
		for (int i = start; i <= M; i++) {
			num[i] = true;
			dfs(i + 1, cnt + 1);
			num[i] = false;
		}
	}
}

int main() {
	cin >> M >> N;

	dfs(1, 0);

}
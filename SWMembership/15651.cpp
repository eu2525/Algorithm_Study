#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;
bool visited[8] = { false };

void dfs(int cnt) {
	if (cnt == m) {
		for (auto x : vec) {
			cout << x << " ";
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			vec.push_back(i);
			dfs(cnt + 1);
			vec.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;

	dfs(0);

}

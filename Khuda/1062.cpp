#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
bool visited[27] = { false };
vector<int> noun[51];
vector<int> vec;
int print_result = 0;

void dfs(int idx, int cnt) {
	if (cnt == K - 5) {
		int result = 0;
		for (int i = 0; i < N; i++) {
			bool read = true;
			for (int j = 0; j < noun[i].size(); j++) {
				int a = noun[i][j];
				if (visited[a] == false) {
					read = false;
				}
			}
			if (read == true) {
				result++;
			}
		}
		print_result = max(print_result, result);
		return;
	}
	else {
		if (idx == 26)
			return;

		if (idx != 0 && idx != 13 && idx != 19 && idx != 8 && idx != 2) {
			visited[idx] = true;
			dfs(idx + 1, cnt + 1);
			visited[idx] = false;
		}

		dfs(idx + 1, cnt);
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		a = a.substr(4, a.length());

		//tica
		for (int j = 0; j < 4; j++)
			a.pop_back();

		for (int j = 0; j < a.size(); j++) {
			int alpha = a[j] - 'a';
			if (alpha != 0 && alpha != 2 && alpha != 8
				&& alpha != 13 && alpha != 19) {
				if (find(noun[i].begin(), noun[i].end(), alpha) == noun[i].end()) {
					noun[i].push_back(alpha);
					vec.push_back(alpha);
				}
			}
		}
	} 
  
	if (K < 5) {
		cout << 0 << '\n';
		return 0;
	}
	else {
		dfs(0, 0);
		cout << print_result << endl;
	}

}

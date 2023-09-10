#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
bool visited[100001] = { false };

void bfs() {
	queue<pair<int,int>> que;
	que.push(make_pair(K,0));
	while (!que.empty()) {
		pair<int,int> num = que.front();
		visited[num.first] = true;
		que.pop();
		if (num.first == N) {
			cout << num.second << '\n';
			return;
 		}
		else if (num.first < N) {
			int next_num1 = num.first + 1;
			if (visited[next_num1] == false) {
				que.push(make_pair(next_num1, num.second + 1));
			}
		}
		else {
			int next_num1 = num.first + 1;
			int next_num2 = num.first - 1;

			if (num.first != 0 && num.first % 2 == 0) {
				int next_num = num.first / 2;
				if (visited[next_num] == false) {
					que.push(make_pair(next_num, num.second));
				}
			}

			if (visited[next_num1] == false) {
				que.push(make_pair(next_num1, num.second + 1));
			}

			if (next_num2 >= 0 && visited[next_num2] == false) {
				que.push(make_pair(next_num2, num.second + 1));
			}
		}
	}
}

int main() {

	cin >> N >> K;
	bfs();
}

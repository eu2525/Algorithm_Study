#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		que.push(i);
	}

	cout << "<";
	while (!que.empty()) {
		for (int i = 1; i < K; i++) {
			que.push(que.front());
			que.pop();
		}
		
		cout << que.front();
		que.pop();
		if (que.size() != 0) {
			cout << ", ";
		}
		else {
			cout << ">";
		}
	}
}

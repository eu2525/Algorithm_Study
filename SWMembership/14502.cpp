#include <iostream>
#include <queue>
using namespace std;

int N, M;
int lab[9][9];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int max_num = 0;
queue<pair<int,int>> number2;

int dfs() {
	int copylab[9][9] = { 0 };
	copy(&lab[0][0], &lab[0][0] + 81, &copylab[0][0]);

	queue<pair<int, int>> q;
	q = number2;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (0 <= xx && xx < N && 0 <= yy && yy < M) {
				if (copylab[xx][yy] == 0) {
					copylab[xx][yy] = 2;
					q.push(make_pair(xx, yy));
				}
			}
		}
	}
	int num_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copylab[i][j] == 0) {
				num_cnt += 1;
			}
		}
	}

	return num_cnt;
}

void makewall(int cnt) {
	if(cnt == 3){
		int num = dfs();
		max_num = max(max_num, num);
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (lab[i][j] == 0) {
					lab[i][j] = 1;
					makewall(cnt + 1);
					lab[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			lab[i][j] = a;
			if (a == 2) {
				number2.push(make_pair(i, j));
			}
		}
	}

	makewall(0);

	cout << max_num << '\n';
}

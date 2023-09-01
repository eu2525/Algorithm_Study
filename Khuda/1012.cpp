#include <iostream>
using namespace std;

int M, N, K;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool check[51][51] = { false };
int land[51][51] = { 0 };
int cnt;

void dfs(int x, int y) {
	if (check[x][y] == true) {
		return;
	}
	else {
		check[x][y] = true;

		if (land[x][y] == 1) {
			for (int i = 0; i < 4; i++) {
				int row = x + dx[i];
				int col = y + dy[i];
				if (0 <= row && row < M && 0 <= col && col < N) {
					if (land[row][col] == 1) {
						dfs(row, col);
					}
				}
			}
		}
	}
}

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			check[i][j] = false;
			land[i][j] = 0;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		init(); //배열 초기화

		cin >> M >> N >> K;

		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			land[x][y] = 1;
		}

		cnt = 0;
		for (int row = 0; row < M; row++) {
			for (int col = 0; col < N; col++) {
				if (land[row][col] == 1 && check[row][col] == false)
					cnt += 1;
				dfs(row, col);
			}
		}
		cout << cnt << '\n';
	}

}
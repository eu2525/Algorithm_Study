#include <iostream>
using namespace std;

int n, m;
int cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int map[501][501] = { 0 };
bool visited[501][501] = { false };

void dfs(int row, int col) {
	cnt += 1;
	visited[row][col] = true;
	for (int i = 0; i < 4; i++) {
		int x = row + dx[i];
		int y = col + dy[i];
		if (x >= 0 && x < n && y >= 0 && y < m) {
			if (map[x][y] == 1 && visited[x][y] == false) {
				dfs(x, y);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int max_num = 0; // 그림의 넓이 저장
	int pic_num = 0; // 그림의 개수 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false && map[i][j] == 1) {
				pic_num += 1;
				cnt = 0;
				dfs(i, j);
				max_num = max(max_num, cnt);
			}
		}
	}
	cout << pic_num << '\n';
	cout << max_num;
}

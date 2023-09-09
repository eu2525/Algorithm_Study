#include <iostream>
#include <queue>
using namespace std;

int m, n, h;
int map[101][101][101] = { 0 };
int dx[6] = { -1, 1, 0, 0 , 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0 , 0,  0, 0, 1, -1 };
queue<pair<pair<int, int>, int>> que;

void bfs() {
	while (!que.empty()) {
		pair<pair<int, int>, int> point = que.front();
		que.pop();
		int x = point.first.first;
		int y = point.first.second;
		int z = point.second;
		// 탐색
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h) {
				if (map[nx][ny][nz] == 0 || map[nx][ny][nz] > map[x][y][z] + 1) {
					map[nx][ny][nz] = map[x][y][z] + 1;
					que.push(make_pair(make_pair(nx, ny), nz));
				}
			}
		}
	}
}

int main() {
	cin >> m >> n >> h;
	//배열에 저장
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int t = 0; t < m; t++) {
				cin >> map[t][j][i];
				if (map[t][j][i] == 1)
					que.push(make_pair(make_pair(t, j), i));
			}
		}
	}
	// BFS 진행
	bfs();
	// Map 배열 탐색 후 최소 며칠이 걸리는지 출력
	int max_num = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int t = 0; t < m; t++) {
				if (map[t][j][i] == 0) {
					cout << "-1" << '\n';
					return 0;
				}
				else {
					max_num = max(max_num, map[t][j][i]);
				}
			}
		}
	}
	cout << max_num - 1 << '\n';
}

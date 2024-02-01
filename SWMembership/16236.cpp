#include <iostream>
#include <queue>
using namespace std;

int n;
int aqua[21][21] = { 0 };
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int fx, fy;
int shark_size = 2;
int shark_eat = 0;
int result = 0;
bool endd = false;
bool eat = false;
pair<int, int> shark;

void bfs(int r, int c) {
	bool visited[21][21] = { 0 };
	queue<pair<pair<int, int>, int>> q;
	int temp = 999999999;
	q.push(make_pair(make_pair(r, c), 0));
	visited[r][c] = true;
	while (!q.empty()) {
		int x = q.front().first.first; // 열 좌표
		int y = q.front().first.second; // 행 좌표
		int cnt = q.front().second; // 현재 시간
		if (aqua[x][y] > 0 && aqua[x][y] < shark_size && temp == cnt) {
			if (fx > x || (fx == x && fy > y)){
				fy = y;
				fx = x;
				continue;
			}
		}
		q.pop();

		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
				if (aqua[nx][ny] <= shark_size) {// 지나가거나 먹을 수 있는 경우
					if (aqua[nx][ny] > 0 && aqua[nx][ny] < shark_size && !eat) { //물고기를 먹을 수 있는 경우
						eat = true; // 한 마리 먹음
						fx = nx; //시작 위치를 물고기를 먹었던 위치로
						fy = ny;
						temp = cnt + 1; // 한 마리 먹는데걸린 시간
						result += temp; // 총 시간에 추가
					}
					else { // 물고기를 못먹는 경우
						q.push(make_pair(make_pair(nx, ny), cnt + 1));
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
	//최종 상어 위치의 값을 0으로 초기화 (먹음을 의미)
	aqua[fx][fy] = 0;
	//다음 시작 시점을 이야기  
	shark = { fx,fy };
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> aqua[i][j];
			if (aqua[i][j] == 9) {
				aqua[i][j] = 0;
				shark = { i,j };
			}
		}
	}

	while (true) {
		bfs(shark.first, shark.second);
		if (eat == true) {
			eat = false;
			shark_eat += 1;
			if (shark_eat == shark_size) {
				shark_size += 1;
				shark_eat = 0;
			}
		}
		else {
			break;
		}
	}

	cout << result << '\n';

}

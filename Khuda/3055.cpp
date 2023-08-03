#include <iostream>
#include <string>;
#include <vector>
#include <queue>
using namespace std;

pair<int, int> destination;
queue<pair<int, int>> water_que; // 물 좌표
queue<pair<int, int>> s_que; // 고슴도치 좌표
int R, S;
string pond[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0;

bool dfs() {
	int result = 0;
	while (!s_que.empty()) {
		// 물 먼저 이동
		int water_cnt = water_que.size();
		for (int i = 0; i < water_cnt; i++) {
			int row = water_que.front().first;
			int col = water_que.front().second;
			water_que.pop();
			for (int i = 0; i < 4; i++) {
				int dx_row = row + dx[i];
				int dy_col = col + dy[i];
				if (dx_row >= 0 && dy_col >= 0 && dx_row < R && dy_col < S) {
					if (pond[dx_row][dy_col] == ".") {
						pond[dx_row][dy_col] = "*";
						water_que.push(make_pair(dx_row, dy_col));
					}
				}
			}
		}
		// 쥐 이동
		int s_cnt = s_que.size();
		for (int i = 0; i <  s_cnt; ++i) {
			int s_row = s_que.front().first;
			int s_col = s_que.front().second;
			s_que.pop();
			for (int i = 0; i < 4; ++i) {
				int sdx_row = s_row + dx[i];
				int sdy_col = s_col + dy[i];
				//목적지를 찾으면
				if ((sdx_row == destination.first) && (sdy_col == destination.second)) {
					cnt++;
					return true;
				}

				if (sdx_row >= 0 && sdy_col >= 0 && sdx_row < R && sdy_col < S) {
					if (pond[sdx_row][sdy_col] == ".") {
						pond[sdx_row][sdy_col] = "S";
						s_que.push(make_pair(sdx_row, sdy_col));
					}
				}
			}
		}
		cnt++;
	}
	return false;
}

int main() {
	cin >> R >> S;
	for (int i = 0; i < R; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < S; j++) {
			string w = a.substr(j, 1);
			pond[i][j] = w;
			if (w == "*")
				water_que.push(make_pair(i, j));
			else if (w == "S")
				s_que.push(make_pair(i, j));
			else if (w == "D")
				destination = make_pair(i, j);
		}
	}
    
	bool find = dfs();

	if (find == true)
		cout << cnt << '\n';
	else
		cout << "KAKTUS" << '\n';
}

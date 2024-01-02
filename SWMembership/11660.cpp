#include <iostream>
using namespace std;

long long su[1025][1025] = { 0 };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int M, N;
	cin >> M >> N;
    
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			int a;
			cin >> a;
			su[i][j] = su[i][j - 1] + a;
		}
	}
    
	for (int j = 0; j < N; j++) {
		int s_x, s_y, e_x, e_y;
		cin >> s_x >> s_y >> e_x >> e_y;
		int min_y = min(s_y, e_y);
		int max_y = max(s_y, e_y);
		int result = 0;
		for (int i = min(s_x, e_x); i <= max(s_x, e_x); i++) {
			result += (su[i][max_y] - su[i][min_y - 1]);
		}
		cout << result << '\n';
	}
}

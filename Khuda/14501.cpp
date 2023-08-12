#include <iostream>
using namespace std;

int money[21] = { 0 };
int day[21] = { 0 };
int N;
int max_num = 0;

void dfs(int d, int m) {
	if (d > N) {
		return;
	}
	else {
		//그날의 일을 하는 경우
		if (d + day[d] <= N + 1) {
			int day_m = money[d]; // 상담 보수
			max_num = max(max_num, m + day_m); 
			dfs(d + day[d], m + day_m); // 그 상담이 끝나는 날로 가서 진행
		}
		//그 날의 일을 하지 않고 그냥 다음 날 업무로 넘어가는 경우
		dfs(d + 1, m);
	}
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> day[i] >> money[i];
	}
	dfs(1, 0);

	cout << max_num << '\n';

}

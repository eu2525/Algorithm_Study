#include <iostream>
#include <string>;
using namespace std;

string num[101];
int strike[101] = { 0 };
int ball[101] = { 0 };

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> num[i] >> strike[i] >> ball[i];

	}

	int cnt = 0;
	for (int j = 123; j <= 987; j++) {
		bool find = true;
		string comp_j = to_string(j);
		if (comp_j[0] == '0' || comp_j[1] == '0' || comp_j[2] == '0') continue; // 0이 들어있는 수
		else if (comp_j[0] == comp_j[1] || comp_j[0] == comp_j[2] || comp_j[1] == comp_j[2]) continue; // 서로 다른 수로 구성되지 않은 경우
		else {
			for (int n = 0; n < N; n++) {
				int s = 0;
				int b = 0;
				string origin = num[n];
				for (int t = 0; t < 3; t++) {
					if (comp_j[t] == origin[t]) s++; //자리수의 수가 같은 경우
					else {
						if (comp_j[t] == origin[0] || comp_j[t] == origin[1] || comp_j[t] == origin[2]) {
							// 자리수의 수가 같지 않을 때 다른 자리수에 수가 있는지 확인
							b++;
						}
					}
				}
				if (s != strike[n] || b != ball[n]) find = false;
			}
			if (find == true) cnt++;
		}
	}
	cout << cnt << '\n';
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<pair<int, int>> docu_inter;
		int N;
		cin >> N;
		
		for (int j = 0; j < N; j++) {
			int docu, inter;
			cin >> docu >> inter;
			docu_inter.push_back(make_pair(docu, inter));
		}
		
		sort(docu_inter.begin(), docu_inter.end());

		int min_value = docu_inter[0].second;
		int cnt = 1;
		for (int j = 1; j < N; j++) {
			int value = docu_inter[j].second;
			if (min_value > value) {
				cnt += 1;
				min_value = value;
			}
		}
		cout << cnt << '\n';
	}
}
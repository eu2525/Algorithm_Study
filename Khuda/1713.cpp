#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rec; // 추천인을 담은 배열
int rec_cnt[101] = { 0 }; // 추천수를 저장하는 배열

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;

		if (rec_cnt[a] != 0) {
			rec_cnt[a] += 1;
		}
		else {
			if (rec.size() >= N) {
				int min_idx = 0;
				int min_cnt = rec_cnt[rec[0]];
				for (int j = 1; j < rec.size(); j++) {
					int idx = rec[j];
					int cnt = rec_cnt[idx];
					if (min_cnt > cnt) {
						min_idx = j;
						min_cnt = cnt;
					}
				}
				rec_cnt[rec[min_idx]] = 0;
				rec.erase(rec.begin() + min_idx);
			}
			rec.push_back(a);
			rec_cnt[a] += 1;
		}
	}

	sort(rec.begin(), rec.end());

	for (auto x : rec) {
		cout << x << ' ';
	}

	return 0;
}

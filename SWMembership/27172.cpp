#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> card; // card 번호와 플레이어 번호를 저장
bool check[10000001]; // 카드를 가지고 있는지 확인
int score[10000001] = { 0 }; // 점수를 계산

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int max_idx = 0; //카드 번호 중 가장 큰 수
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		card.push_back(make_pair(a, i));
		check[a] = true;
		max_idx = max(max_idx, a);
	}
	//card를 "낮은 수" -> "높은 수"로 정렬
	sort(card.begin(), card.end()); 
	// 점수를 계산
	for (int i = 0; i < N; i++) {
		int start = card[i].first * 2;
		while (start <= max_idx) {
			if (check[start] == true) {
				score[start] -= 1;
				score[card[i].first] += 1;
			}
			start += card[i].first;
		}
	}
	// 플레이어 번호 순서대로 정렬
	sort(card.begin(), card.end(), compare);

	for (auto x : card) {
		cout << score[x.first] << " ";
	}

	return 0;
}

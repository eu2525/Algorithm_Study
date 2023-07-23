#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int result = 0;
bool check[101] = { false };
vector<int> card;

void select(int cnt, int sum) {
	if (cnt == 3) {
		if (sum <= M) 
			result = max(result, sum);
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (check[i] == false) {
				check[i] = true;
				select(cnt + 1, sum + card[i]);
				check[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a <= M);
		card.push_back(a);
	}
	select(0, 0);
	cout << result << '\n';
}

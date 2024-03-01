#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> lines;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		lines.push_back(make_pair(a, b));
	}
	
	sort(lines.begin(), lines.end());

	int start = lines[0].first;
	int end = lines[0].second;
	int length = 0;
	for (int i = 1; i < lines.size(); i++) {
		if (end >= lines[i].first) {
			end = max(end, lines[i].second);
		}
		else {
			length += (end - start);
			start = lines[i].first;
			end = lines[i].second;
		}
	}
	
	length += (end - start);

	cout << length << '\n';
}

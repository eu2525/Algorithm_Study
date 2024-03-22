#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sorted[11] = { 0 };

void merge(int low, int mid, int high) {
	vector<int> u;
	int i = low;
	int j = mid + 1;
	while (i <= mid && j <= high) {
		if (sorted[i] > sorted[j]) {
			u.push_back(sorted[i]);
			i++;
		}
		else {
			u.push_back(sorted[j]);
			j++;
		}
	}
	for(int t = j; t <= high; t++)
    		u.push_back(sorted[t]);
	for(int t = i; t <= mid; t++)
		u.push_back(sorted[t]);
	for(int t = low; t <= high; t++) {
		sorted[t] = u[t - low];
	}
}

void mergesort(int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, mid, high);
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> sorted[j];
    		}
		mergesort(0, 9);
		cout << sorted[2] << '\n';
	}
}

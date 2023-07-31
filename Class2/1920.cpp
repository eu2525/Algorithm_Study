#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int A[100001];
int sorted[100001];

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            sorted[k] = A[i];
            i++;
        }
        else if (A[i] > A[j]) {
            sorted[k] = A[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        for (int t = j; t <= end; t++) {
            sorted[k] = A[t];
            k++;
        }
    }
    else {
        for (int t = i; t <= mid; t++) {
            sorted[k] = A[t];
            k++;
        }
    }

    for (int t = start; t <= end; t++) {
        A[t] = sorted[t];
    }
}

void merge_sort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, mid, end);
    }
}

bool binary_search(int num){
	int s = 0;
	int e = N - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (num < A[mid]) {
			e = mid - 1;
		}
		else if (num > A[mid]) {
			s = mid + 1;
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

    merge_sort(0, N - 1);

	cin >> M;
	for (int j = 0; j < M; j++) {
		int b;
		cin >> b;
		bool find = binary_search(b);
		if (find == true) {
			cout << "1" << '\n';
		}
		else {
			cout << "0" << '\n';
		}
	}
}

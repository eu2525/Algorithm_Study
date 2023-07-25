#include <iostream>
#include <string>
using namespace std;

string alpha[20001];
string sorted[20001];
int N;

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        int i_lg = alpha[i].size(); 
        int j_lg = alpha[j].size();
        if (i_lg < j_lg) {
            sorted[k] = alpha[i];
            i++;
        }
        else if (i_lg > j_lg) {
            sorted[k] = alpha[j];
            j++;
        }
        else {
            if (alpha[i].compare(alpha[j]) <= 0) {
                sorted[k] = alpha[i];
                i++;
            }
            else {
                sorted[k] = alpha[j];
                j++;
            }
        }
        k++;
    }

    if (i > mid) {
        for (int t = j; t <= end; t++) {
            sorted[k] = alpha[t];
            k++;
        }
    }
    else {
        for (int t = i; t <= mid; t++) {
            sorted[k] = alpha[t];
            k++;
        }
    }

    for (int t = start; t <= end; t++) {
        alpha[t] = sorted[t];
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

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
        cin >> alpha[i];
	}

    merge_sort(0, N - 1);
    
    cout << alpha[0] << '\n';
    for (int i = 1; i < N; i++) {
        if (alpha[i - 1] != alpha[i]) {
            cout << alpha[i] << '\n';
        }
    }
}

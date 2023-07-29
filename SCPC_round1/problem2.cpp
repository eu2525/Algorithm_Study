#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int Answer;

bool compare(int a, int b) {
	return a > b;
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, D;
		vector<int> left_idx;
		vector<int> right_idx;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N >> D;

		int standard = D / 3;


		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			if (a <= D && a >= -D) {
				if (a < 0) {
					int new_a = abs(a);
					left_idx.push_back(new_a);
				}
				else {
					right_idx.push_back(a);
				}
			}
		}
		sort(right_idx.begin(), right_idx.end());
		sort(left_idx.begin(), left_idx.end(), compare);
		
		int s = 0, e = 0; //e는 양수 
		
		int l_size = left_idx.size();
		int r_size = right_idx.size();
		
		Answer = max(l_size, r_size); //반대쪽

		while (s < l_size && e < r_size) {
			if (right_idx[e] < standard) {
				if (left_idx[s] + 2 * right_idx[e] <= D) {
					Answer = max(Answer, e + (l_size - s) + 1);
					e++;
				}
				else {
					s++;
				}
			}
			else {
				if (left_idx[s] * 2 + right_idx[e] <= D) {
					Answer = max(Answer, e + (l_size - s) + 1);
					e++;
				}
				else {
					s++;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

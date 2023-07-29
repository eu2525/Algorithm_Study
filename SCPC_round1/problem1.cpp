#include <iostream>
using namespace std;

int N, num_a, num_b;
int Answer = 0;

void sum_subset(int a) {
	if (N >= a) {
		int mod = N - a;
		if (mod % num_b == 0) {
			int box = (a / num_a) + (mod / num_b);
			Answer = max(Answer, box);
			sum_subset(a + num_a);
		}
		else
			sum_subset(a + num_a);
	}
}


int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N >> num_a >> num_b;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		sum_subset(0);
		/////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
		Answer = 0;
	}

	return 0;//Your program should return 0 on normal termination.
}

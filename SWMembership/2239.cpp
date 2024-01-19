#include <iostream>
#include <string>
using namespace std;

bool row[10][10] = { false };
bool col[10][10] = { false };
bool box[10][10] = { false };
int sudoku[100][100] = { 0 };

// v 값을 넣을 수 있으면 다음으로 아니면 false.
bool check(int r, int c, int v) {

	int box_row = (r - 1) / 3;
	int box_col = (c - 1) / 3;
	int box_idx = 3 * box_row + box_col;

	if (row[r][v] == true || col[c][v] == true || box[box_idx][v] == true) {
		return false;
	}
	else {
		return true;
	}
}

void dfs(int r, int c) {
	if (r == 10) {
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				cout << sudoku[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}
	else {
		if (sudoku[r][c] == 0) {
			for (int i = 1; i <= 9; i++) {
				if (check(r, c, i) == true) { // sudoku[r][c]에 i라는 value 들어갈 수 있다면 
					int box_row = (r - 1) / 3;
					int box_col = (c - 1) / 3;
					int box_idx = 3 * box_row + box_col;
					row[r][i] = true;
					col[c][i] = true;
					box[box_idx][i] = true;
					sudoku[r][c] = i;
					if (c == 9)
						dfs(r + 1, 1);
					else
						dfs(r, c + 1);

					row[r][i] = false;
					col[c][i] = false;
					box[box_idx][i] = false;
					sudoku[r][c] = 0;
				}
				else if (i == 9) {
					return;
				}
			}
		}
		else {
			if (c == 9)
				dfs(r + 1, 1);
			else
				dfs(r, c + 1);
		}
	}
}

int main() {
	for (int i = 1; i <= 9; i++) {
		string a;
		cin >> a;
		for (int j = 1; j <= 9; j++) {
			int b = a[j - 1] - '0';
			if (b != 0) {
				int box_row = (i - 1) / 3;
				int box_col = (j - 1) / 3;
				int box_idx = 3 * box_row + box_col;
				row[i][b] = true;
				col[j][b] = true;
				box[box_idx][b] = true;
			}
			sudoku[i][j] = b;
		}
	}

	dfs(1, 1);

	return 0;
}

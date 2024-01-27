#include<bits/stdc++.h>
using namespace std;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}


int dir[8][2] = {{1, 2}, {1, -2}, { -1, 2}, { -1, -2}, {2, 1}, { -2, 1}, {2, -1}, { -2, -1}};

bool isItSafe(vector<vector<int>>& grid, int i, int j, int n) {
	return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == -1;
}

void display(vector<vector<int>>& grid, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << "\t";
		}
		cout << endl;
	}
}

void f(vector<vector<int>>& grid, int i, int j, int n, int cnt) {

	if (cnt == n * n - 1) {
		grid[i][j] = cnt;
		display(grid, n);
		cout << endl;
		cout << endl;
		grid[i][j] = -1;
		return;
	}

	for (int d = 0; d < 8; d++) {
		int x = i + dir[d][0];
		int y = j + dir[d][1];
		if (isItSafe(grid, x, y, n)) {
			grid[i][j] = cnt;
			f(grid, x, y, n, cnt + 1);
			grid[i][j] = -1;
		}
	}
}

void knightTour(int n, int i, int j) {
	//-1 denotes cell is vacant
	vector<vector<int>> grid(n, vector<int>(n, -1));
	f(grid, i, j, n, 0);
}

int main() {

	init();

	int n = 5;
	knightTour(n, 0, 0);

	return 0;
}
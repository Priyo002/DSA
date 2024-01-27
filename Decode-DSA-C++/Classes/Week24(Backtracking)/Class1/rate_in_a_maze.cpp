#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const long long INF = 1e18;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

int ans;
int dir[4][2] = {{1, 0}, { -1, 0}, {0, -1}, {0, 1}};

void f(vector<vector<int>>& grid, int n , int i, int j) {

	if (i == n - 1 && j == n - 1) {
		ans++;
		return;
	}
	grid[i][j] = 2;//2 means visited

	for (int d = 0; d < 4; d++) {
		int x = i + dir[d][0];
		int y = j + dir[d][1];
		if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y]) continue;
		f(grid, n, x, y);
		grid[x][y] = 0;
	}

}

int ratInMaze(vector<vector<int>>& grid, int n) {
	ans = 0;
	f(grid, n, 0, 0);
	return ans;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();
	int n = 4;

	//0 means can go
	//1 means blockage

	vector<vector<int> > maze = {
		{ 0, 1, 1, 1 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 1, 0, 0, 0 }
	};
	cout << ratInMaze(maze, n);

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
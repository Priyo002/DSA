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
bool isValid(int r, int c, vector<vector<char>>& board) {
	int sr = r;
	int sc = c;
	while (sr >= 0 && sc >= 0) {
		if (board[sr][sc] == 'Q') return false;
		sr--;
		sc--;
	}
	sr = r;
	sc = c;
	while (sc >= 0) {
		if (board[sr][sc] == 'Q') return false;
		sc--;
	}
	sc = c;
	while (sr < 8 && sc >= 0) {
		if (board[sr][sc] == 'Q') return false;
		sr++;
		sc--;
	}
	return true;
}

int ans = 0;
void solve(vector<vector<char>>& arr, int col) {
	if (col == 8) {
		ans++;
		return;
	}
	for (int row = 0; row < 8; row++) {
		if (arr[row][col] == '*') continue;
		if (isValid(row, col, arr)) {
			arr[row][col] = 'Q';
			solve(arr, col + 1);
			arr[row][col] = '.';
		}
	}
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	vector<vector<char>> arr(8, vector<char>(8));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}

	solve(arr, 0);
	cout << ans;

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
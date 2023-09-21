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

void solve() {
	char arr[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (arr[i][0] == 'X') ans++;
		if (arr[i][9] == 'X') ans++;
	}
	for (int j = 1; j < 9; j++) {
		if (arr[0][j] == 'X') ans++;
		if (arr[9][j] == 'X') ans++;
		if (arr[1][j] == 'X') ans += 2;
		if (arr[8][j] == 'X') ans += 2;
	}
	for (int i = 2; i < 8; i++) {
		if (arr[i][1] == 'X') ans += 2;
		if (arr[i][8] == 'X') ans += 2;
		if (arr[i][2] == 'X') ans += 3;
		if (arr[i][7] == 'X') ans += 3;
	}
	for (int j = 3; j < 7; j++) {
		if (arr[2][j] == 'X') ans += 3;
		if (arr[7][j] == 'X') ans += 3;
		if (arr[3][j] == 'X') ans += 4;
		if (arr[6][j] == 'X') ans += 4;
	}
	if (arr[4][3] == 'X') ans += 4;
	if (arr[5][3] == 'X') ans += 4;
	if (arr[4][6] == 'X') ans += 4;
	if (arr[5][6] == 'X') ans += 4;
	if (arr[4][4] == 'X') ans += 5;
	if (arr[5][4] == 'X') ans += 5;
	if (arr[4][5] == 'X') ans += 5;
	if (arr[5][5] == 'X') ans += 5;
	cout << ans << endl;

}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}
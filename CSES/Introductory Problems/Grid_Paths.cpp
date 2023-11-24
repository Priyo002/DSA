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

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
int f(int i, int j, int x, int y) {
	if (i < 0 || j < 0 || i >= 7 || j >= 7) return 0;
	//if (dp[i][j] != -1) return dp[i][j];
	if (i == x && j == y) return 1;
	int ans = 0;
	for (int d = 0; d < 4; d++) {
		int k1 = i + dir[d][0];
		int k2 = j + dir[d][1];
		ans += f(k1, k2, x, y);
	}
	return ans;
}

void solve() {
	//memset(dp, -1, sizeof(dp));
	// vector<vector<char>> arr(7,vector<char>(7));
	// for(int i=0;i<7;i++){
	// 	for(int j=0;j<7;j++){
	// 		cin >> arr[i][j];
	// 	}
	// }
	// int ans = 0;
	// for(int i=0;i<7;i++){
	// 	for(int j=0;j<7;j++){

	// 	}
	// }
	cout << f(0, 0, 6, 6);

}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();


	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
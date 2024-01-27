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

int n, m; //dimension of the input matrix
char mat[105][105];//input matrix
int dp[105][105][105];


int f(int i, int j, int x, int y) {
	if (i > n || j > m || x > n || y > m || mat[i][j] == '#' || mat[x][y] == '#') return 0;
	if (i == n && j == m) return mat[i][j] == '*';
	if (dp[i][j][x] != -1) return dp[i][j][x];

	int res = INT_MIN;

	res = max(res, f(i + 1, j, x + 1, y));
	res = max(res, f(i + 1, j, x, y + 1));
	res = max(res, f(i, j + 1, x + 1, y));
	res = max(res, f(i, j + 1, x, y + 1));

	res += (mat[i][j] == '*');
	res += (mat[x][y] == '*');

	//remove repitition
	if (i == x && j == y && mat[i][j] == '*')
		res--;

	return dp[i][j][x] = res;
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	int t;
	cin >> t;
	while (t--) {
		//n->row, m->col
		cin >> m >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> mat[i][j];
			}
		}
		cout << f(1, 1, 1, 1) << endl;
	}

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
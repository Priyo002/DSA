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

int isPali(string s, char ch) {
	int i = 0;
	int j = s.size() - 1;
	int cnt = 0;
	while (i < j) {
		if (s[i] != s[j]) {
			if (s[i] == ch) {
				i++;
				cnt++;
			}
			else if (s[j] == ch) {
				j--;
				cnt++;
			}
			else return INT_MAX;
		}
		else {
			i++;
			j--;
		}
	}
	return cnt;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;


	int ans = INT_MAX;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		int k = isPali(s, ch);
		ans = min(ans, k);
	}
	cout << ((ans == INT_MAX) ? -1 : ans) << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
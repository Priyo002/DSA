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
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++) {
		char ch1 = s1[i];
		char ch2 = s2[i];
		if (ch1 == ch2) continue;
		if (ch1 == 'R' && ch2 == 'S') c1++;
		else if (ch1 == 'P' && ch2 == 'R') c1++;
		else if (ch1 == 'S' && ch2 == 'P') c1++;
		else c2++;
	}
	//cout << c1 << " " << c2 << endl;
	if (c1 > c2) cout << 0;
	else {
		cout << ((c2 + c1) / 2 + 1) - c1;
	}
	//cout << max(c1, c2);
	cout << endl;
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
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
	int n, k, m;
	cin >> n >> k >> m;

	string str;
	cin >> str;

	unordered_map<char, int> mp;
	for (auto ch : str) mp[ch]++;

	char ch = 'a';
	int t = k;
	char last = (char)(ch + (k - 1));
	while (t--) {
		unordered_map<char, int> temp = mp;
		bool flag = true;
		for (int i = m - 1; i >= 0; i--) {
			temp[str[i]]--;
			if (str[i] == ch) {
				flag = false;
				for (char j = 'a'; j <= last; j++) {
					int freq = temp[j];
					if (freq >= n - 1) continue;
					cout << "NO" << endl;
					for (int i = 0; i < n; i++) {
						cout << j;
					}
					cout << endl;
					return;
				}
				break;
			}
		}
		if (flag) {
			cout << "NO" << endl;
			for (int i = 0; i < n; i++) {
				cout << ch;
			}
			cout << endl;
			return;
		}
		ch++;
	}
	cout << "YES" << endl;
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
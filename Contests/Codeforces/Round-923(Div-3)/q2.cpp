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

	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	unordered_map<int, vector<char>> mp;

	char ch = 'a';
	string ans = "";

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			mp[0].push_back(ch);
			ans.push_back(ch);
			ch++;
		}
		else if (mp.find(arr[i] - 1) != mp.end()) {
			vector<char> temp = mp[arr[i] - 1];
			char k;

			for (int j = 0; j < temp.size(); j++) {
				if (temp[j] != '.') {
					k = temp[j];
					mp[arr[i] - 1][j] = '.';
					break;
				}
			}

			mp[arr[i]].push_back(k);
			ans.push_back(k);
		}
	}

	cout << ans << endl;
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
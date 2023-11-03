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

int sum(string& str) {
	int s = 0;
	for (int i = 0; i < str.size(); i++) {
		s += (str[i] - '0');
	}
	return s;
}

bool check(string& str, int l, int total) {
	int s1 = 0;
	for (int i = 0; i < l / 2; i++) {
		s1 += (str[i] - '0');
	}
	if (s1 * 2 == total) return true;
	return false;
}

void solve() {
	int n;
	cin >> n;
	vector<string> arr(n);
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<vector<int>> v(1000);
	vector<int> e, o;
	for (int i = 0; i < n; i++) {
		int k = arr[i].size();
		if (k & 1) o.push_back(i);
		else e.push_back(i);
		v[k].push_back(i);

	}
	set<pair<int, int>> st;
	for (auto it : o) {
		string temp1 = arr[it], temp2 = arr[it];
		for (int i = 1; i <= 5; i += 2) {

			for (auto j : v[i]) {
				string t = arr[j];
				temp1 += t;
				temp2 = t + temp2;

				int s = sum(temp1);

				if (check(temp1, temp1.size(), s)) {
					st.insert({it, j});
					ans += 1;
				}

				s = sum(temp2);

				if (check(temp2, temp2.size(), s)) {
					if (st.count({it, j})) {
						auto m = st.find({it, j});
						if (m->first != m->second) {
							st.insert({it, j});
							ans += 1;
						}
						else ans++;
					}
					else {
						st.insert({it, j});
						ans++;
					}
				}

			}
		}
	}
	for (auto it : e) {
		string temp1 = arr[it], temp2 = arr[it];
		for (int i = 2; i <= 4; i += 2) {

			for (auto j : v[i]) {
				string t = arr[j];
				temp1 += t;
				temp2 = t + temp2;

				int s = sum(temp1);

				if (check(temp1, temp1.size(), s)) {
					st.insert({it, j});
					ans += 1;
				}

				s = sum(temp2);

				if (check(temp2, temp2.size(), s)) {
					if (st.find({it, j}) != st.end()) {
						auto m = st.find({it, j});
						if (m->first != m->second) {
							st.insert({it, j});
							ans += 1;
						}
						else ans++;
					}
					else {
						st.insert({it, j});
						ans++;
					}
				}

			}
		}
	}
	for (auto x : st) cout << x.first << "," << x.second << " ";
	cout << endl;
	cout << st.size();
	cout << endl;
	cout << ans;
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
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
	string s;
	cin >> s;

	unordered_map<char, int> mp;
	for (char ch : s) {
		mp[ch]++;
	}
	string str = "";
	bool flag = false;
	char ch;
	for (auto i : mp) {
		if ((i.second & 1) && flag == false) {
			flag = true;
			ch = i.first;
		}
		else if ((i.second & 1) && flag) {
			cout << "NO SOLUTION";
			return;
		}
		else {
			for (int j = 0; j < i.second / 2; j++) {
				str.push_back(i.first);
			}
		}
	}
	string temp = str;
	if (flag) {
		for (int i = 0; i < mp[ch]; i++) {
			str.push_back(ch);
		}
	}
	reverse(temp.begin(), temp.end());
	cout << str << temp;
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	// int t;
	// cin >> t;
	// while(t--)
	solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
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
	string str;
	cin >> str;

	vector<int> arr(26, 0);
	for (auto& ch : str) {
		arr[ch - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) {
			cout << (char)('a' + i) << endl;
			return;
		}
	}

	for (char i = 'a'; i <= 'z'; i++) {
		for (char j = 'a'; j <= 'z'; j++) {
			string temp = "";
			temp += i, temp += j;
			auto x = str.find(temp);
			if (x == string::npos) {
				cout << temp << endl;
				return;
			}
		}
	}
	for (char i = 'a'; i <= 'z'; i++) {
		for (char j = 'a'; j <= 'z'; j++) {
			for (char k = 'a'; k <= 'z'; k++) {
				string temp = "";
				temp += i, temp += j, temp += k;
				auto x = str.find(temp);
				if (x == string::npos) {
					cout << temp << endl;
					return;
				}
			}
		}
	}
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
#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const int INF = 1e18;

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
	string str;
	cin >> str;
	vector<string> arr(5);
	for (int i = 0; i < 5; i++) cin >> arr[i];
	char ch1 = str[0], ch2 = str[1];
	for (int i = 0; i < 5; i++) {
		string temp = arr[i];
		if (temp[0] == ch1 || temp[1] == ch2) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int32_t main() {

	init();
	solve();

}
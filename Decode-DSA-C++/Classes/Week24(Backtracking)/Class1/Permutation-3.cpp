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

void f(string &str, int i) {
	if (i == str.size() - 1) {
		cout << str << endl;
		return;
	}
	unordered_set<char> st;
	for (int idx = i; idx < str.size(); idx++) {
		if (st.count(str[idx])) continue;

		st.insert(str[idx]);
		swap(str[idx], str[i]);
		f(str, i + 1);
		swap(str[idx], str[i]);
	}
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	string str = "aba";
	f(str, 0);

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
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
vector<int> even, odd;
int n;
void fo(vector<int>& arr) {
	int i = 0, j = 0;
	bool flag = true;
	while (arr.size() < n) {
		if (flag) {
			if (arr.size() == n) break;
			arr.push_back(odd[j++]);
			if (arr.size() == n) break;
			arr.push_back(odd[j++]);
			if (arr.size() == n) break;
			arr.push_back(even[i++]);
			flag = false;
		}
		else {
			if (arr.size() == n) break;
			arr.push_back(even[i++]);
			flag = true;
		}
	}
}

void solve() {
	cin >> n;
	vector<int> arr;
	odd.clear();
	even.clear();
	for (int i = 1; i <= n; i++) {
		if (i & 1) odd.push_back(i);
		else even.push_back(i);
	}
	fo(arr);
	for (auto x : arr) {
		cout << x << " ";
	}
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
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

	set<int> st;
	for (auto x : arr) st.insert(x);

	vector<int> temp;
	for (auto x : st) {
		temp.push_back(x);
	}

	int m = -1;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] != i) {
			m = i;
			break;
		}
	}
	if (m == -1) {
		m = temp.size();
	}
	set<int> stt, stt2;
	for (int i = 0; i <= m; i++) {
		stt.insert(i);
		stt2.insert(i);
	}

	int i = 0, idx = -1;
	while (i < n) {
		if (stt.count(arr[i]))
			stt.erase(arr[i]);
		if (stt.size() && *(stt.begin()) == m) {
			idx = i + 1;
			break;
		}
		i++;
	}

	if (idx == -1 || idx == n) {
		cout << -1 << endl;
		return;
	}

	for (int j = idx; j < n; j++) {
		if (stt2.count(arr[j]))
			stt2.erase(arr[j]);
	}

	if (st.size() && *(stt2.begin()) != m) cout << -1 << endl;
	else {
		cout << 2 << endl;
		cout << 1 << " " << i + 1 << endl;
		cout << idx + 1 << " " << n << endl;
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
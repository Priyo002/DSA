#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define endl '\n'
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

struct bag {

	int K;
	multiset<int> left, right;

	void init(int _k) {
		K = _k;
		left.clear();
		right.clear();
	}

	void rebalance() {
		while (left.size() > K) {
			int val = *left.rbegin();
			right.insert(val);
			left.erase(left.find(val));
		}
		while (left.size() < K && right.size()) {
			int val = *right.begin();
			left.insert(val);
			right.erase(right.find(val));
		}
	}

	void add(int x) {
		if (left.empty() && right.empty()) {
			left.insert(x);
		}
		else {
			if (x <= *left.rbegin()) {
				left.insert(x);
			}
			else {
				right.insert(x);
			}
		}
		rebalance();
	}

	void remove(int x) {
		if (left.find(x) != left.end()) {
			left.erase(left.find(x));
		}
		else if (right.find(x) != right.end()) {
			right.erase(right.find(x));
		}
		rebalance();
	}

	int getMedian() {
		rebalance();
		return *left.rbegin();
	}
	void print() {

		for (auto x : left) cout << x << " ";
		cout << 'r' << ' ';
		for (auto x : right) cout << x << " ";
		cout << endl;
	}
};

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)cin >> arr[i];

	int temp = (k & 1) ? k / 2 + 1 : k / 2;

	bag ds;
	ds.init(temp);

	vector<int> ans;

	for (int i = 0; i < n; i++) {

		ds.add(arr[i]);

		if (i - k >= 0) ds.remove(arr[i - k]);

		if (i >= k - 1) {
			ans.push_back(ds.getMedian());
		}
	}
	for (auto x : ans) cout << x << " ";

}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int _t = 1;
	//cin >> _t;
	while (_t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}

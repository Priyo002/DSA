#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		multiset<int> mt;
		set<int> st;
		//vector<int> v(n);
		int last;
		for (int i = 0; i < n; i++) {
			cin >> last;
			st.insert(last);
			mt.insert(last);
		}
		if (mt.count(last) < k) {
			cout << "NO" << endl;
			continue;
		}
		if (st.size() == 1) {
			cout << "YES" << endl;
			continue;
		}
		for (auto it : st) {
			if (mt.count(it) >= k) {
				cout <<
			}
		}

	}

}
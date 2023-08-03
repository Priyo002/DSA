#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	int n, k;
	cin >> n >> k;
	int m = INT_MAX;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n <= k) {
		cout << *min_element(arr.begin(), arr.end());
		return ;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		m = min(m, arr[i]);
		cnt++;
		if (cnt == k ) {
			cout << m << " ";
			m = INT_MAX;
			cnt = 0;
		}

	}
	int rem = n % k;
	if (rem != 0) {
		m = INT_MAX;
		for (int i = n - rem ; i < n; i++) {
			m = min(m, arr[i]);
		}
		cout << m;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();

}
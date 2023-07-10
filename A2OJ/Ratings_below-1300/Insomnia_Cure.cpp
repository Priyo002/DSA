#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	vector<int> arr(d + 1, 0);
	for (int i = 1; i < d + 1; i++) {
		if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
			arr[i]++;
		}
	}
	int cnt = 0;
	for (int i = 1; i < d + 1; i++) {
		if (arr[i] == 0) cnt++;
	}
	cout << d  - cnt;

}
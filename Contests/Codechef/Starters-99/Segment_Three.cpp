#include<bits/stdc++.h>
using namespace std;

int calculate(int curr, int req) {
	int m1 = curr % 3;
	int m2 = req % 3;
	if (m1 == m2) return 0;
	if (m2 > m1) return m2 - m1;
	return m2 + (3 - m1);
}

int cal(vector<int> a) {
	int ans = 0;
	for (int i = 3; i < a.size(); i++) {
		int operations = calculate(a[i], a[i - 3]);
		ans += operations;
		a[i] = a[i - 3];
	}
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<int>> X;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if ((i + j + k) % 3 == 0)
						X.push_back({i, j, k});
				}
			}
		}
		int ans = INT_MAX;

		for (auto vec : X) {
			vector<int> temp = vec;
			for (auto x : a) {
				temp.push_back(x);
			}
			ans = min(ans, cal(temp));
		}

		cout << ans << endl;

	}

}
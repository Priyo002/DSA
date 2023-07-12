#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		vector<int> tmp(m);
		for (int j = 0; j < m; j++) {
			cin >> tmp[j];
		}
		v.push_back(tmp);
	}

	vector<int> strong(n), weak(m);
	for (int i = 0; i < m; i++) {
		weak[i] = v[0][i];
	}
	for (int i = 0; i < n; i++) {
		int tmp_max = v[i][0];
		for (int j = 0; j < m; j++) {
			tmp_max = max(tmp_max, v[i][j]);
			weak[j] = min(weak[j], v[i][j]);
		}
		strong[i] = tmp_max;
	}

	sort(strong.begin(), strong.end());
	for (auto i : weak) {
		if (binary_search(strong.begin(), strong.end(), i)) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;


}
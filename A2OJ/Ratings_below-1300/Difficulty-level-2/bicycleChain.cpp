#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	float n, m;
	cin >> n;
	vector<float> v1(n), ans;
	for (int i = 0; i < n; i++) cin >> v1[i];
	cin >> m;
	vector<float> v2(m);
	for (int i = 0; i < m; i++) cin >> v2[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			float temp = v2[j] / v1[i];
			int temp1 = v2[j] / v1[i];
			if (temp1 == temp)
				ans.push_back(temp);
		}
	}
	float maxi = *max_element(ans.begin(), ans.end());
	int cnt = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (maxi == ans[i]) cnt++;
	}
	cout << cnt;

}
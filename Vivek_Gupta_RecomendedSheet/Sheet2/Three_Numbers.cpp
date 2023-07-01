#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int k, s;
	cin >> k >> s;
	int cnt = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			int sum = s - (i + j);
			if (sum >= 0 && sum <= k) cnt++;
		}
	}
	cout << cnt;
}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i <= max(n, m); i++) {
		int a2 = n - i;
		int a = m - (i * i);
		if (a < 0) continue;
		if (a2 == (a * a)) {
			cnt++;
		}

	}
	cout << cnt;


}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int a[1010];
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + m + 1);
	int b[1010];
	for (int i = 1; i <= m; i++) {
		b[i] = a[i];
	}
	int l = n, k = 1;
	int max1 = 0;
	while (l--) {
		max1 += b[m];
		b[m]--;
		sort(b + 1, b + m + 1);
	}
	l = n; int min1 = 0;
	while (l--) {
		for (int i = 1; i <= m; i++) {
			if (a[i] > 0) {
				min1 += a[i];
				a[i]--;
				break;
			}
		}
	}
	cout << max1 << " " << min1;

}
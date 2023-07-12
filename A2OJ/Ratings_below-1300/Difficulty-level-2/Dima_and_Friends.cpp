#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int sum = 0;
	int cnt = 0;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= 5; i++) {
		if ((sum + i) % (n + 1) != 1) {
			cnt++;
		}
	}
	cout << cnt << endl;

}
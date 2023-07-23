#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long n, k, l;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	k = count(a, a + n, a[0]);
	l = count(a, a + n, a[n - 1]);
	if (a[0] == a[n - 1])k = n * (n - 1) / 2;
	else  k = k * l;
	cout << a[n - 1] - a[0] << " " << k;
}


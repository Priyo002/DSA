#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, a, index[100001];
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a;
		index[a] = i;
	}

	int m, b;
	cin >> m;
	long long Vasya = 0, Petya = 0;
	while (m--) {
		cin >> b;
		Vasya += index[b];
		Petya += (n + 1 - index[b]);
	}
	cout << Vasya << " " << Petya;
	return 0;

}
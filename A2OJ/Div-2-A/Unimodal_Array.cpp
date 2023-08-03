#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vin for(int i=0;i<n;i++)

void solve() {
	int b, l, n, i;
	cin >> n;
	int a[n + 1];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i < n; i++)
	{
		if (a[i] <= a[i - 1]) break;
	}
	for (b = i + 1; b < n; b++)
	{
		if (a[b] != a[b - 1]) break;
		else if (a[b] < a[i - 1]) break;
	}
	for (l = b; l < n; l++)
	{
		if (a[l] >= a[l - 1])
		{
			cout << "NO";
			return ;
		}
	}

	cout << "YES";
	return;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();

}
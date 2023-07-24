#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, p, i, j, a[100001], b[1000001], h;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		if (a[p] == -1) {}
		else if (a[p] == 0)
		{
			a[p] = i;
			h++;

		}
		else if (b[p] == 0)
		{
			b[p] = i - a[p];
			a[p] = i;

		}
		else if (i - a[p] == b[p])
		{
			a[p] = i;

		}
		else
		{
			a[p] = -1;
			h--;
		}
	}
	cout << h << endl;
	for (i = 1; i <= 100000; i++)
	{
		if (a[i] > 0)
		{
			cout << i << " " << b[i] << endl;
		}
	}



	return 0;


}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int b[n];
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		vector<int>c;
		for (int i = 1; i <= n; i++)
		{
			c.push_back(i);
		}

		for (int i = 0; i < n; i++)
		{

			if (b[i] == 0)
			{
				swap(c[i + 1], c[i]);
			}

		}

		for (int i = 0; i < n; i++) {
			cout << c[i] << " ";
		}
		cout << endl;
	}

	return 0;

}
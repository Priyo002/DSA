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
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		long long ans = 0;

		for (int i = 1; i < n;)
		{
			long long inc = 0, dec = 0;
			while (i < n && arr[i] > arr[i - 1]) {
				inc++;
				i++;
			}

			while (i < n && arr[i] < arr[i - 1])
			{
				dec++;
				i++;
			}
			if (arr[i] == arr[i - 1])
				i++;
			long long total = inc + dec;
			ans = max(ans, total);
		}
		cout << ans + 1 << endl;
	}
	return 0;


}
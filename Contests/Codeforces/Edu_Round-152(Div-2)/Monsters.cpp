#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 300005;
int T, n, k, a[maxn];
pair<int, int>p[maxn];
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			p[i] = make_pair(-((a[i] - 1) % k + 1), i);
		}
		sort(p + 1, p + n + 1);
		for (int i = 1; i <= n; i++)
		{
			cout << p[i].second << " ";
		}
		cout << endl;
	}
}
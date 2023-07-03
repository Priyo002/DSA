#include <bits/stdc++.h>
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

		vector<int> dir(n);
		vector<long long> power(n);

		for (int i = 0; i < n; i++)
		{
			cin >> dir[i];
			cin >> power[i];
		}

		stack<int> asteroidStack;
		vector<int> result;

		for (int i = 0; i < n; i++)
		{
			if (dir[i] == 1)
			{
				asteroidStack.push(i);
			}
			else
			{
				while (!asteroidStack.empty() && power[asteroidStack.top()] < power[i])
				{
					power[i] += power[asteroidStack.top()];
					asteroidStack.pop();
				}

				if (!asteroidStack.empty())
				{
					if (power[asteroidStack.top()] == power[i])
					{
						asteroidStack.pop();
					}
					else
					{
						power[asteroidStack.top()] += power[i];
					}
				}
				else
				{
					result.push_back(i);
				}
			}
		}

		while (!asteroidStack.empty())
		{
			result.push_back(asteroidStack.top());
			asteroidStack.pop();
		}

		sort(result.begin(), result.end());

		cout << result.size() << endl;
		for (int i : result)
		{
			cout << i + 1 << " ";
		}
		cout << endl;
	}
	return 0;

}
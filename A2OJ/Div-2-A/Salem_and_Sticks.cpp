#include <bits/stdc++.h>

using namespace std;

int n, A[1010], c, m = 1e9, b;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 2; i <= 99; i++)
	{
		b = 0;
		for (int j = 1; j <= n; j++)
		{
			if (A[j] < i) b += i - 1 - A[j];
			if (A[j] > i) b += A[j] - i - 1;
		}
		if (b < m)
		{
			m = b;
			c = i;
		}
	}
	printf("%d %d\n", c, m);
	return 0;
}

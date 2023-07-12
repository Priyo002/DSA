#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, i, j;
	char c;
	cin >> n;
	int a[26] = {};
	for (i = 0 ; i < n ; i++)
	{
		cin >> c;
		a[c - 97]++;
	}
	for (i = 0 ; i < 26 ; i++)
	{
		for (j = a[i] ; j > 0 ; j--)
		{
			char temp;
			temp = i + 97;
			cout << temp;
		}
	}
}
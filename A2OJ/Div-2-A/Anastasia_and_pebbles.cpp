#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {

	long long n, k, i;
	cin >> n >> k;
	double a, sum = 0;
	for (i = 0; i < n; i++)
	{
		cin >> a;
		sum += ceil(a / k);
	}
	k = ceil(sum / 2);
	cout << k << endl;


}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();

}
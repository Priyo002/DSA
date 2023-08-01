#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	ll n, j;
	cin >> n;
	ll sum = (n * (n + 1)) / 2;
	ll sum1 = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> j;
		sum1 += j;
	}
	cout << sum - sum1;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();
}
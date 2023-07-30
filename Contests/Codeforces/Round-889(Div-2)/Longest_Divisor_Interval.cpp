#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	ll n;
	cin >> n;
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		if (n % i == 0) cnt++;
		else break;
	}
	cout << cnt << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}
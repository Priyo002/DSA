#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	ll n;
	cin >> n;
	if (n < 4) {
		cout << 0 << " " << n ;
	}
	else {
		ll k = n / 4;
		if (k & 1) {
			cout << k << " " << 3 - (n % 4);
		}
		else
			cout << k << " " << n % 4;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();

}
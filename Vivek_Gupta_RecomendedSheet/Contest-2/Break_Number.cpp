#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	ll n, a;
	cin >> n;
	vector<ll> v;
	for (ll i = 0; i < n; i++) {
		cin >> a;
		if ((a & 1) == 0) {
			v.push_back(a);
		}
	}
	ll ans = 0;
	ll cnt = 0;
	for (ll i = 0; i < v.size(); i++) {
		//cout << v[i] << " ";
		ll temp = v[i];
		while (temp % 2 == 0) {
			temp /= 2;
			cnt++;
		}
		ans = max(ans, cnt);
		cnt = 0;
	}
	cout << ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();

}
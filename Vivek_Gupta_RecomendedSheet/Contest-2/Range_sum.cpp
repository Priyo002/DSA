#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	ll a, b;
	cin >> a >> b;
	ll k;
	if (b < a) {
		k = b;
		swap(a, b);
	}
	else k = a;
	ll sum = (b * (b + 1)) / 2;
	ll sum1 = (a * (a + 1)) / 2;
	cout << abs(sum - sum1 + k) << endl;
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
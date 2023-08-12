#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void solve() {
	ll n, k;
	cin >> n >> k;

	string s[6] = {"012", "102", "120", "210", "201", "021"};
	cout << s[n % 6][k];
}

int main() {

	init();


	solve();

}
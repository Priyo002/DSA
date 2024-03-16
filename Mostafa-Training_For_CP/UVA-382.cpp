#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const long long INF = 1e18;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

int f(int n) {

	int sum = 0;

	for (int i = 1; i  < n; i++) {
		if (n % i == 0) {
			sum += i;

		}
	}

	return sum;
}

void solve(int n) {

	int sum = f(n);
	cout << setw(5) << n;
	cout << "  ";
	if (sum == n) {
		cout << "PERFECT" << endl;
	}
	else if (sum < n) {
		cout << "DEFICIENT" << endl;
	}
	else cout << "ABUNDANT" << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t;
	cout << "PERFECTION OUTPUT" << endl;
	while ((cin >> t) && t)
		solve(t);
	cout << "END OF OUTPUT" << endl;

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
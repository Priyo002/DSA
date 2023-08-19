#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define inf 1e18
const int mod = 1e9 + 7;

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

}

const int p = 1e9 + 7, N = 1e5;
int fact[N];

int addm(int x, int y) {
	return ((x % p) + (y % p)) % p;
}

int subm(int x, int y) {
	return ((x - y) % p + p) % p;
}

int mulm(int x, int y) {
	return ((x % p) * (y % p)) % p;
}

int powr(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = mulm(res, x);
		x = mulm(x, x);
		y /= 2;
	}
	return res;
}

int inv(int x) {
	return powr(x, p - 2);
}

int ncr(int n, int r) {
	return mulm(mulm(fact[n], inv(r)), inv(fact[n - r]));

}

int divm(int x, int y) {
	/*
		(a/b)%p : (a*powr(b,-1))%p
		According to Fermat's Thorem,
		powr(b,p) = b (mod p);
		powr(b,p-1) = 1 (mod p);
		powr(b,p-2) = powr(b,-1) (mod p);
	*/
	return mulm(x, powr(y, p - 2)); //Fermat's Theorem
}

void calculate_factorials() {
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mulm(fact[i - 1], i);
	}
}

int32_t main() {

	init();

	cout << addm(2, 5) << endl;
	cout << subm(-3, 5) << endl;
	cout << mulm(5, 4) << endl;
	cout << divm(56, 2) << endl;
	calculate_factorials();
	cout << fact[5] << endl;
	cout << ncr(5778, 123) << endl;
}

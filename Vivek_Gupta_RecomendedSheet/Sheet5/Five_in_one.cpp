#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool ispali(int n) {
	string s = to_string(n);
	string p = s;
	reverse(p.begin(), p.end());
	return s == p;
}

int divi(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) cnt++;
	}
	return cnt;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n ;
	vector<int> v(n);
	int maxi = INT_MIN;
	int mini = INT_MAX;
	int prime = 0;
	int pali = 0;
	int div = INT_MIN;
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (isPrime(v[i])) prime++;
		if (ispali(v[i])) pali++;
		maxi = max(maxi, v[i]);
		mini = min(mini, v[i]);
		int k = divi(v[i]);
		if (div < k) {
			div = k;
			ans = v[i];
		}
		else if (div == k && ans < v[i]) ans = v[i];
	}
	cout << "The maximum number : " << maxi << endl;
	cout << "The minimum number : " << mini << endl;
	cout << "The number of prime numbers : " << prime << endl;
	cout << "The number of palindrome numbers : " << pali << endl;
	cout << "The number that has the maximum number of divisors : " << ans;
}
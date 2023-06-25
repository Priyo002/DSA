#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long n;
	cin >> n;
	long long temp = n;
	long long sum = 0;
	long long x = 1;
	while (n) {
		sum = sum * 10 + (n % 10);
		n /= 10;
	}
	cout << sum << endl;
	if (sum == temp)
		cout << "YES";
	else cout << "NO";
}
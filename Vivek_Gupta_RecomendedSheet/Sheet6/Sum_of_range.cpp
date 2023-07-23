#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long a, b;
	cin >> a >> b;
	long long sum = 0, sum1 = 0, sum2 = 0;
	for (long long i = min(a, b); i <= max(a, b); i++) {
		sum += i;
		if ((i & 1) == 1) sum1 += i;
		if ((i & 1) == 0) sum2 += i;
	}
	cout << sum << endl;
	cout << sum2 << endl;
	cout << sum1;

}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	long long i;
	int even = 0, odd = 0, pos = 0, neg = 0;
	while (n--) {
		cin >> i;
		if (i % 2 == 0) even++;
		else odd++;
		if (i < 0) neg++;
		else if (i > 0) pos++;
	}
	cout << "Even: " << even << endl;
	cout << "Odd: " << odd << endl;
	cout << "Positive: " << pos << endl;
	cout << "Negative: " << neg;
}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	long long n;
	cin >> n;
	long long cnt = 0;
	while (n) {
		int rem = n % 10;
		if (rem == 4 || rem == 7)
			cnt++;
		n /= 10;
	}
	if (cnt == 4 || cnt == 7)
		cout << "YES";
	else cout << "NO";
	return 0;
}
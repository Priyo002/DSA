#include<bits/stdc++.h>
using namespace std;

void reverseof(int n) {
	if (n == 0) return;
	cout << n % 10;
	reverseof(n / 10);
}

int actualreverse(int n, int sum) {
	if (n == 0) {
		return sum;
	}
	return actualreverse(n / 10, sum * 10 + n % 10);

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	reverseof(n);
	cout << endl;
	int ans = actualreverse(n, 0);
	cout << ans;
}
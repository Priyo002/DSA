#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int cnt = 0;
	int maxi = INT_MIN;
	while (n--) {
		int k;
		cin >> k;
		if (k > maxi) {
			cnt++;
			maxi = k;
		}
	}
	cout << cnt;
}
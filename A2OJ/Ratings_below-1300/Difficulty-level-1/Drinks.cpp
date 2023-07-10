#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (arr[i] / 100.0);
	}
	ans /= n;
	ans *= 100;
	cout <<  ans;


}
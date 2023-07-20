#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int mini = INT_MAX;
	int maxi = INT_MIN;
	while (n--) {
		int a;
		cin >> a;
		mini = min(mini, a);
		maxi = max(maxi, a);
	}
	cout << mini << " " << maxi;
}
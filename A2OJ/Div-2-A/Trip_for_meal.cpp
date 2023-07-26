#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	cout << max(min(min(a, b) * (n - 1), min(a, b) + c * (n - 2)), 0) << endl;

}
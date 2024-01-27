#include<bits/stdc++.h>
using namespace std;

int findNumberOfWays(int n) {
	if (n < 0) return 0;
	if (n == 0)return 1;
	return findNumberOfWays(n - 1) + findNumberOfWays(n - 2) + findNumberOfWays(n - 3);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif



	int n;
	cin >> n;
	cout << findNumberOfWays(n) << endl;
	return 0;



}
#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
	if (n == 1) return 1;
	int ans = n * fact(n - 1);
	return ans;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif


	int n;
	cin >> n;
	cout << fact(n);

}
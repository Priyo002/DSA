#include<bits/stdc++.h>
using namespace std;


int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int prev = 0;
	int fib = 1;
	int temp = fib;
	for (int i = 1; i <= n; i++) {
		cout << prev << " ";
		temp = fib;
		fib += prev;
		prev = temp;
	}

}
#include<bits/stdc++.h>
using namespace std;

void print(int n) {
	if (n == 0) return;
	cout << n << endl;
	print(n - 1);

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	print(n);

}
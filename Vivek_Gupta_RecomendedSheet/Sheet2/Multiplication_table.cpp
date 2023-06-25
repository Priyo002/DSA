#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 1; i <= 12; i++) {
		cout << n << " * " << i << " = " << n*i << endl;
	}

}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, a, b;
	cin >> n >> a >> b;
	if (n - a <= b)
		cout << n - a;
	else {
		while (n - a > b) {
			a++;
		}
		cout << n - a + 1;
	}

}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	float n;
	cin >> n;

	if (n == (int)n) {
		cout << "int " << (int)n;
	}
	else {
		cout << "float " << (int)n << " " << setprecision(3) << n - (int)n;
	}
}
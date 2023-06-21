#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << "Difference = " << a*b - c*d;
}
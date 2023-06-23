#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	double a, b, c, d;
	cin >> a >> b >> c >> d;

	if ( (b * log(a)) > (d * log(c)) )
		cout << "YES";
	else
		cout << "NO";
}
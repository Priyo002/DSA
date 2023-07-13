#include<bits/stdc++.h>
#include<ios>
#include<iomanip>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	double x, p;
	cin >> x >> p;
	double ans = (p * 100) / (100 - x);
	cout << fixed;
	cout << setprecision(2);
	cout << ans ;

}
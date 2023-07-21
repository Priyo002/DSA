#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	double n;
	cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double a;
		cin >> a;
		sum += a;
	}
	cout << setprecision(7) << sum / n;

}
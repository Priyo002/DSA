#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	float x;
	cin >> x;
	if (x > 100 || x < 0) cout << "Out of Intervals";
	else if (x >= 0 && x <= 25) cout << "Interval [0,25]";
	else if (x > 25 && x <= 50) cout << "Interval (25,50]";
	else if (x > 50 && x <= 75) cout << "Interval (50,75]";
	else if (x > 75 && x <= 100) cout << "Interval (75,100]";

	return 0;

}
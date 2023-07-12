#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b, x, y;
	cin >> a >> b >> x >> y;
	long long score1 = (a * 2) + b;
	long long score2 = (x * 2) + y;
	if (score2 > score1) {
		cout << "Ronaldo";
	}
	else if (score2 < score1) {
		cout << "Messi";
	}
	else cout << "Equal";

	return 0;
}
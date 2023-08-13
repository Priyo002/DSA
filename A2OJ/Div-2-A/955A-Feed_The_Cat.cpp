#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void solve() {

	float hh, mm;
	cin >> hh >> mm;
	float h, d, c, n;
	cin >> h >> d >> c >> n;

	float min = (20 - hh - 1) * 60 + (60 - mm);
	float h1 = h + (min * d);
	float c1 = ((ceil(h1 / n) * c) - (0.2 * (ceil(h1 / n) * c))) * 1.0;
	float c2 = (ceil(h / n) * c) * 1.0;
	if (hh >= 20) {
		cout << ((ceil(h / n) * c) - (0.2 * (ceil(h / n) * c))) * 1.0;
	}
	else if (c1 < c2) {
		cout << c1;
	}
	else cout << c2;
	cout << setprecision(4);


}

int main() {

	init();
	solve();

}
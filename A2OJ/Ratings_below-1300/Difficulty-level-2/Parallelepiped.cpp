#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long hl, hw, wl;
	cin >> hl >> hw >> wl;
	long long prod = (wl * hw) / hl;
	long long w = sqrt(prod);
	long long h = hw / w;
	long long l = hl / h;
	cout << 4 * (l + w + h);

}
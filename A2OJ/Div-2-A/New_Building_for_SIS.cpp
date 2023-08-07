#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	int n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	while (k--) {
		int fa, ta, fb, tb;
		cin >> ta >> fa >> tb >> fb;
		if (ta == tb) {
			cout << abs(fa - fb) << endl;
		}
		else {
			if (fa >= a && fa <= b) {
				int temp = abs(ta - tb) + abs(fb - fa);
				cout << temp << endl;
			}
			else {
				int t;
				if (fa > b) {
					t = abs(fa - b) + abs(ta - tb) + abs(fb - b);
				}
				else {
					t = abs(fa - a) + abs(ta - tb) + abs(fb - a);
				}
				cout << t << endl;
			}
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();

}

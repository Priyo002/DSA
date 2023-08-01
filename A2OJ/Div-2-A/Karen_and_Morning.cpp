#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	int h, m;
	int mincurr;
	int need = 0;
	char ch;

	cin >> h >> ch >> m;
	mincurr = 60 * h + m;

	while (true) {
		if (mincurr / 60 / 10 + mincurr / 60 % 10 * 10 == mincurr % 60) {
			break;
		}

		need++;

		mincurr = (mincurr + 1) % 1440;
	}

	cout << need << '\n';
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();

}
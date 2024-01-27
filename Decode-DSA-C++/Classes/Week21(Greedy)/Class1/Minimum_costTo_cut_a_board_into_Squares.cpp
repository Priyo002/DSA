#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define inf 1e18
const int mod = 1e9 + 7;

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

}


/* Problem : 1

 * A board of length M and width N is given. The task
 * is to break this board into M*N squares such that cost
 * of breaking is minimum. The cutting for each edge will be
 * given for the board in two arrays X[] and Y[]. In short, you
 * need to choose such a sequence of cutting such that cost is
 * minimized. Return the minimized cost.
 *
 * Input :
 * M = 6, N = 4
 * X[] = {2,1,3,1,4} (cost of Vertical edge cut)
 * Y[] = {4,1,2} (cost of horizontal edge cut)
 * Output : 42

 */

int minCost_toBreakGrid(int n, int m, vector<int>&ver, vector<int>&hor) {
	sort(ver.begin(), ver.end(), greater<int>());
	sort(hor.begin(), hor.end(), greater<int>());
	int hz = 1;
	int vr = 1;
	int h = 0;
	int v = 0;
	int ans = 0;
	while (h < hor.size() && v < ver.size()) {
		if (ver[v] > hor[h]) {
			ans += (ver[v] * vr);
			hz++;
			v++;
		}
		else {
			ans += (hor[h] * hz);
			vr++;
			h++;
		}
	}
	while (h < hor.size()) {
		ans += (hor[h] * hz);
		vr++;
		h++;
	}
	while (v < ver.size()) {
		ans += (ver[v] * vr);
		hz++;
		v++;
	}
	return ans;
}


int32_t main() {

	init();

	int n, m;
	cin >> m >> n;
	vector<int> horizontal, vertical;
	for (int i = 0; i < m - 1; i++) {
		int x;
		cin >> x;
		vertical.push_back(x);
	}
	for (int i = 0; i < n - 1; i++) {
		int y;
		cin >> y;
		horizontal.push_back(y);
	}

	cout << minCost_toBreakGrid(n, m, vertical, horizontal);

}
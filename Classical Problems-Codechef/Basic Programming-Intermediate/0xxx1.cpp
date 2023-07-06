#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	int t;
	cin >> t;
	int MOD = 1e9 + 7;
	while (t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		int cnt = 0;
		int lo = 0;
		int hi = n - 1;
		while (lo < hi) {
			if (str[hi] == '1' && str[lo] == '0') {
				cnt += hi - lo ;
				lo++;
				hi--;
			}
			else if (str[lo] == '1') lo++;
			else hi--;
		}
		cout << cnt % MOD << endl;
	}

}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	string s;
	cin >> s;
	int cnt = 1;
	int ans = INT_MIN;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) cnt++;
		else cnt = 1;
		ans = max(cnt, ans);
	}
	cout << max(ans, cnt);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();

}
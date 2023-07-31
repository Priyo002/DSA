#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

void solve() {
	string s;
	cin >> s;
	if (s.size() < 7) {
		cout << "no";
	}
	else {
		int idx = -1;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				idx = i;
				break;
			}
		}
		for (int i = idx; i < s.size(); i++) {
			if (s[i] == '0') cnt++;
		}
		if (cnt >= 6 && idx != -1) cout << "yes";
		else
			cout << "no";
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();
}
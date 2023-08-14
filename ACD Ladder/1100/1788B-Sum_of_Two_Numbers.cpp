#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
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

void solve() {
	string s;
	cin >> s;
	if ((s[s.size() - 1] - '0') % 2 == 0) {
		int d = stoi(s);
		cout << d / 2 << " " << d / 2 << endl;
		return;
	}
	bool flag = true;
	string str1 = "";
	string str2 = "";
	for (int i = 0; i < s.size(); i++) {
		int k = s[i] - '0';
		if (k % 2 == 0) {
			string temp = to_string(k / 2);
			str1 += temp;
			str2 += temp;
		}
		else if (flag) {
			string temp1 = to_string(k / 2 + 1);
			string temp2 = to_string(k / 2);
			str1 += temp1;
			str2 += temp2;
			flag = false;
		}
		else {
			string temp1 = to_string(k / 2 + 1);
			string temp2 = to_string(k / 2);
			str1 += temp2;
			str2 += temp1;
			flag = true;
		}
	}
	int d1 = stoi(str1);
	int d2 = stoi(str2);
	cout << d1 << " " << d2 << endl;
}

int main() {
	init();

	ll t;
	cin >> t;
	while (t--) solve();
}
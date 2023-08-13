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

//"Danil", "Olya", "Slava", "Ann" and "Nikita".

void solve() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '_') continue;
		else if (s[i] == 'D' && i + 4 < s.size()) {
			string str = s.substr(i, 5);
			if (str == "Danil") cnt++;
		}
		else if (s[i] == 'O' && i + 3 < s.size()) {
			string str = s.substr(i, 4);
			if (str == "Olya") cnt++;
		}
		else if (s[i] == 'S' && i + 4 < s.size()) {
			string str = s.substr(i, 5);
			if (str == "Slava") cnt++;
		}
		else if (s[i] == 'A' && i + 2 < s.size()) {
			string str = s.substr(i, 3);
			if (str == "Ann") cnt++;
		}
		else if (s[i] == 'N' && i + 5 < s.size()) {
			string str = s.substr(i, 6);
			if (str == "Nikita") cnt++;
		}
	}
	if (cnt == 1) {
		cout << "YES";
	}
	else cout << "NO";
}

int main() {

	init();

	solve();
}


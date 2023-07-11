#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, t;
	cin >> n >> t;
	string s, x; cin >> s;
	int f = 0, e = 0;
	for (int i = 1; i <= t; i++) {
		cin >> x;
		if (x == "substr") {
			cin >> f >> e;
			--f;
			--e;
			for (int i = min(f, e); i <= max(e, f); i++)
				cout << s[i];
			cout << endl;
		}
		else if (x == "sort") {
			cin >> f >> e;
			sort(s.begin() + min(f, e) - 1, s.begin() + max(f, e));
		}
		else if (x == "reverse") {
			cin >> f >> e;
			reverse(s.begin() + min(f, e) - 1, s.begin() + max(f, e));
		}
		else if (x == "front") {

			cout << s.front() << endl;
		}
		else if (x == "back") {

			cout << s.back() << endl;
		}
		else if (x == "push_back") {
			char p; cin >> p;
			s.push_back(p);
		}
		else if (x == "pop_back") {
			s.pop_back();
		}
		else if (x == "print") {
			int pos;
			cin >> pos;
			pos--;
			cout << s[pos] << endl;
		}
	}

}
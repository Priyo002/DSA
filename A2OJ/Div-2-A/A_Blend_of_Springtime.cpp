#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	bool a = 0, b = 0, c = 0;
	string s, x;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		x = s.substr(i, 3);
		if (x == "ABC" || x == "BCA" || x == "CAB" || x == "ACB" || x == "BAC" || x == "CBA") {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

}
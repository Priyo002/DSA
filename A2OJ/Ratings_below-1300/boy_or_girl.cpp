#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	string s;
	cin >> s;
	vector<int> arr(26, 0);
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		int x = s[i] - 97;
		if (arr[x] == 0) cnt++;
		arr[x]++;
	}
	if (cnt % 2 == 0) cout << "CHAT WITH HER!";
	else cout << "IGNORE HIM!";

}
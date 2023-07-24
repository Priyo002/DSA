#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	vector<int> cnt(26, 0);
	for (int i = 0; i < s.size(); ++i)
		cnt[s[i] - 'a']++;
	int odd = 0;
	for (int i = 0; i < 26; ++i)
		if (cnt[i] & 1)
			odd++;
	if ((odd == 0) || (odd & 1))
		cout << "First" << endl;
	else
		cout << "Second" << endl;
	return 0;


}
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
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == 'E' || s[i] == 'e') {
			arr['e' - 97]++;
		}
		else if (s[i] == 'G' || s[i] == 'g') {
			arr['g' - 97]++;
		}
		else if (s[i] == 'Y' || s[i] == 'y') {
			arr['y' - 97]++;
		}
		else if (s[i] == 'P' || s[i] == 'p') {
			arr['p' - 97]++;
		}
		else if (s[i] == 'T' || s[i] == 't') {
			arr['t' - 97]++;
		}
	}

	vector<int> ans;
	ans.push_back(arr['e' - 97]);
	ans.push_back(arr['g' - 97]);
	ans.push_back(arr['y' - 97]);
	ans.push_back(arr['p' - 97]);
	ans.push_back(arr['t' - 97]);

	cout << *min_element(ans.begin(), ans.end());

}
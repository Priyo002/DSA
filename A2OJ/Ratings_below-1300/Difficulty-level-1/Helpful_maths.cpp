#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	cin >> s;
	vector<int> arr;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '+') arr.push_back(s[i] - '0');
	}
	sort(arr.begin(), arr.end());
	int cnt = s.size() / 2;
	string ans = "";
	for (int i = 0; i < arr.size(); i++) {
		ans += to_string(arr[i]);
		if (cnt) {
			ans += "+";
			cnt--;
		}
	}
	cout << ans;
}
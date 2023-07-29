#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	unordered_set<string> ans;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		set<char>st;
		for (int i = 0; i < s.size(); i++) {
			st.insert(s[i]);
		}
		string temp = "";
		for (auto it : st) {
			temp.push_back(it);
		}
		ans.insert(temp);
	}
	cout << ans.size();

}
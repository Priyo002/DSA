#include<bits/stdc++.h>
using namespace std;

void printSubset(string ans, string original) {
	if (original.size() == 0) {
		cout << ans << "\n";
		return;
	}
	char ch = original[0];
	printSubset(ans + ch, original.substr(1));
	printSubset(ans, original.substr(1));
}

void storeSubset(string ans, string original, vector<string> &v) {
	if (original.size() == 0) {
		v.push_back(ans);
		return;
	}
	char ch = original[0];
	storeSubset(ans + ch, original.substr(1), v);
	storeSubset(ans, original.substr(1), v);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string str = "Pri";
	vector<string> v;
	printSubset("", str);
	cout << endl;
	storeSubset("", str, v);
	for (auto i : v) {
		cout << i << endl;
	}

}
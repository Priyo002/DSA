#include<bits/stdc++.h>
using namespace std;

void storeSubset(string ans, string original, vector<string> &v, bool flag) {
	if (original.size() == 0) {
		v.push_back(ans);
		return;
	}
	char ch = original[0], dh;
	if (original.size() > 1) {
		dh = original[1];
	}
	if (original.size() == 1 || ch != dh) {
		if (flag == true)
			storeSubset(ans + ch, original.substr(1), v, true);
		storeSubset(ans, original.substr(1), v, true);
	}
	else if (ch == dh) {
		if (flag == true)
			storeSubset(ans + ch, original.substr(1), v, true);
		storeSubset(ans, original.substr(1), v, false);
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string str = "aabcd";
	vector<string> v;
	storeSubset("", str, v, true);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

}
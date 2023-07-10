#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> arr(26, 0);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int n = s[i] - 97;
		arr[n]++;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != 0) {
			cout << (char)(97 + i) << " : " << arr[i] << endl;
		}
	}

}
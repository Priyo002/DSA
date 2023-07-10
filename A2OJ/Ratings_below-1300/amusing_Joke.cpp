#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string a, b, c;
	cin >> a >> b >> c;
	vector<int> arr(26, 0);
	for (int i = 0; i < c.size(); i++) {
		int x = c[i] - 65;
		arr[x]++;
	}
	for (int i = 0; i < a.size(); i++) {
		int x = a[i] - 65;
		if (arr[x] <= 0) {
			cout << "NO";
			return 0;
		}
		else arr[x]--;
	}
	for (int i = 0; i < b.size(); i++) {
		int x = b[i] - 65;
		if (arr[x] <= 0) {
			cout << "NO";
			return 0;
		}
		else arr[x]--;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] > 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
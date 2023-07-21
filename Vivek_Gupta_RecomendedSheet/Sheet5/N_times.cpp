#include<bits/stdc++.h>
using namespace std;

void repeat(char ch, int n) {
	for (int i = 1; i <= n; i++) {
		cout << ch << " ";
	} cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		char ch;
		cin >> ch;
		repeat(ch, n);
	}
}
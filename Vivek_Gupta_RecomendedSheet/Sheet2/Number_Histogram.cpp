#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	char ch;
	cin >> ch;
	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		while (k--) cout << ch;
		cout << endl;
	}
}
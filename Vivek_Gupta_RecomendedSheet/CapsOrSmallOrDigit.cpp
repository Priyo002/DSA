#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	char ch;
	cin >> ch;
	if (isalnum(ch)) {
		if (isdigit(ch)) {
			cout << "IS DIGIT";
			return 0;
		}
		cout << "ALPHA" << endl;
		if (islower(ch)) cout << "IS SMALL";
		else cout << "IS CAPITAL";
	}
	return 0;

}
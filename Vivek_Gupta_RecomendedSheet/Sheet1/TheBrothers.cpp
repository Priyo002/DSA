#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s1, s2, s3, s4;
	cin >> s1 >> s2;
	cin >> s3 >> s4;
	if (s2 == s4) cout << "ARE Brothers";
	else cout << "NOT";

	return 0;

}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif


	string Key = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
	string Original = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	vector<char> encry(257, 0), decry(257, 0);
	for (int i = 0; i < Key.size(); i++) {
		int j = (int)Original[i];
		encry[j] = Key[i];
	}

	for (int i = 0; i < 62; i++) {
		int j = (int)Key[i];
		decry[j] = Original[i];
	}

	int q;
	string s;
	cin >> q >> s;
	if (q == 1) {
		for (int i = 0; i < s.size(); i++) {
			int j = s[i];
			s[i] = encry[j];
		}
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			int j = s[i];
			s[i] = decry[j];
		}
	}
	cout << s;

}
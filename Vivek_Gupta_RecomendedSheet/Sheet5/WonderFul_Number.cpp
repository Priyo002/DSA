#include<bits/stdc++.h>
using namespace std;

bool isPali(int n) {
	string s = "";
	while (n) {
		int rem = n % 2;
		s += to_string(rem);
		n /= 2;
	}
	string temp = s;
	reverse(s.begin(), s.end());
	if (temp == s) return true;
	return false;
}

bool isOdd(int n) {
	if (n % 2 == 0) 	return false;
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;

	if (isOdd(n) && isPali(n)) {
		cout << "YES";
	}
	else cout << "NO";

}
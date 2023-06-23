#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long a , b, c;
	char ch, ch1;

	cin >> a >> ch >> b >> ch1 >> c;
	switch (ch) {
	case '+' :
		if (a + b == c) {
			cout << "Yes";
			break;
		}
		else {
			cout << a + b;
			break;
		}
	case '-' :
		if (a - b == c) {
			cout << "Yes";
			break;
		}
		else {
			cout << a - b;
			break;
		}
	case '*' :
		if (a * b == c) {
			cout << "Yes";
			break;
		}
		else {
			cout << a*b;
			break;
		}
	}

}
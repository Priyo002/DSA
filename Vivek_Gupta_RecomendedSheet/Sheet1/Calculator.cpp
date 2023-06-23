#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long a, b;
	char op;
	cin >> a >> op >> b;
	switch (op) {
	case '+' : cout << a + b;
		break;
	case '-' : cout << a - b;
		break;
	case '*' : cout << a*b;
		break;
	case '/' : cout << a / b;
		break;
	}

}
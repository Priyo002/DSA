#include<bits/stdc++.h>
using namespace std;

/*
a << b = a/pow(2,b); left shift
a >> b = a*pow(2,b); right shift
*/

string decimal_to_binary(int num) {
	string result = "";
	while (num > 0) {
		if (num % 2 == 0)
			result = "0" + result;
		else
			result = "1" + result;

		num /= 2;
	}
	return result;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n = 23;
	cout << decimal_to_binary(n) << endl;
	n = 32;
	cout << decimal_to_binary(n);

}
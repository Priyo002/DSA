#include<bits/stdc++.h>
using namespace std;

//Euclid's Division Algorithm

//T.C. -> O(log(a+b));

/*
a -> divisor
b -> dividend
*/

int gcd(int a, int b) {
	if (b % a == 0) return a;
	return gcd(b % a, a);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	cout << "GCD is " << gcd(a, b) << endl;

}
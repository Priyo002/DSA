#include<bits/stdc++.h>
using namespace std;

/*
Formula :
	1. (a+b)%c = (a%c + b%c)%c;
	2. (a*b)%c = (a%c * b%c)%c;
	3. (a-b)%c = (a%c - b%c + c)%c;
*/

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int x = INT_MAX;
	cout << x % 5 << endl;
	cout << (x % 5 + 2 % 5) % 5 << endl;

}
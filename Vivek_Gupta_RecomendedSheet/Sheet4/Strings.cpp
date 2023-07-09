#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string a, b;
	cin >> a >> b;
	cout << a.size() << " " << b.size() << endl;
	cout << a << b << endl;
	char temp = a[0];
	char temp1 = b[0];
	a[0] = temp1;
	b[0] = temp;
	cout << a << " " << b;


}
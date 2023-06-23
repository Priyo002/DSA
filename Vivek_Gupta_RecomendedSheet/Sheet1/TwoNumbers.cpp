#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	float a, b;
	cin >> a >> b;
	float c = a / b;
	cout << "floor " << a << " / " << b << " = " << floor(c) << endl;
	cout << "ceil " << a << " / " << b << " = " << ceil(c) << endl;
	cout << "round " << a << " / " << b << " = " << round(c) << endl;
}
#include<bits/stdc++.h>
using namespace std;

void s(int &a, int &b) {
	int temp = b;
	b = a;
	a = temp;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	s(a, b);
	cout << a << " " << b;

}
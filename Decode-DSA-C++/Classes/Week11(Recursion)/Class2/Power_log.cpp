#include<bits/stdc++.h>
using namespace std;

int power(int a, int b) {
	if (b == 1) return a;
	if (b == 0) return 1;
	if (b % 2 == 0) return power(a, b / 2) * power(a, b / 2);
	else return a * power(a, b - 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a , b;
	cin >> a >> b;
	cout << power(a, b);

}
#include<bits/stdc++.h>
using namespace std;

//Using return type
int sum1ton(int n) {
	if (n == 1) return 1;
	return n + sum1ton(n - 1);
}

//Using Parameter
void sum1toN(int sum, int n) {
	if (n == 0) {
		cout << sum << endl;
		return;
	}
	sum1toN(sum + n, n - 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << sum1ton(n);
	cout << endl;
	sum1toN(0, n);

}
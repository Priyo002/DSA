#include<bits/stdc++.h>
using namespace std;

void zigzag(int n) {
	if (n == 0) return;
	cout << n;
	zigzag(n - 1);
	cout << n;
	zigzag(n - 1);
	cout << n;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	int n;
	cin >> n;
	zigzag(n);

}
#include<bits/stdc++.h>
using namespace std;

void print(int n) {

	for (int i = 1; i < n; i++) {
		cout << i << " ";
	}
	cout << n;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	print(n);

}
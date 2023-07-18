#include<bits/stdc++.h>
using namespace std;

int add(int *a, int *b) {
	int sum = *a + *b;
	return sum;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	cout << add(&a, &b);
}
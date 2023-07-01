#include<bits/stdc++.h>
using namespace std;

int digitSum(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, a, b;
	cin >> n >> a >> b;
	long sum = 0;
	for (int i = 1; i <= n; i++) {
		int flag = digitSum(i);
		if (flag >= a && flag <= b) sum += i;
	}
	cout << sum;
}
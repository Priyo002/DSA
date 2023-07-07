#include<bits/stdc++.h>
using namespace std;

bool isDistinct(int n) {
	vector<int> arr(10, 0);
	while (n) {
		int i = n % 10;
		arr[i]++;
		if (arr[i] > 1) return false;
		n /= 10;
	}
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	while (true) {
		n++;
		if (isDistinct(n)) {
			cout << n;
			return 0;
		}
	}
}
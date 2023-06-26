#include<bits/stdc++.h>
using namespace std;

bool check(int n) {
	while (n) {
		int r = n % 10;
		if (r == 7 || r == 4)
			n /= 10;
		else return false;
	}
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	bool flag = true;
	for (int i = a; i <= b; i++) {
		if (check(i)) {
			flag = false;
			cout << i << " ";
		}
	}
	if (flag == true) cout << -1;

}
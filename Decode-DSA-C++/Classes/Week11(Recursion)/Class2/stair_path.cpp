#include<bits/stdc++.h>
using namespace std;

int stair(int n) {
	if (n == 1 ) return 1;
	if (n == 2) return 2;
	return stair(n - 1) + stair(n - 2);
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n ;
	cin >> n;
	cout << stair(n);

}
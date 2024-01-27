#include<bits/stdc++.h>
using namespace std;

int power(int a, int b) {
	if (b == 1) return a;
	int ans = power(a, b / 2);
	return ans * ans ;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	cout << "h";
	cout << power(2, 3);

}
#include<bits/stdc++.h>
using namespace std;

int sumOdd(int sum, int a, int b) {

	if (a > b) return sum;
	else if (a % 2 == 0) return sumOdd(sum, a + 1, b);
	else return sumOdd(sum + a, a + 2, b);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int a , b;
	cin >> a >> b;
	cout << sumOdd(0, a, b);

}
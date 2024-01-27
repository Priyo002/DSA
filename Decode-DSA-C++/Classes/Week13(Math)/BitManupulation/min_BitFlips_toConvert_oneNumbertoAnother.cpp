#include<bits/stdc++.h>
using namespace std;

/*
Q : Calculate the minimum number of bit flips
	to convert from one number to another

Example :
	5 	-> 0101
	11 	-> 1011
	so number of bit flip required will be 3
*/

int minBitsFlip_toConvert(int x, int y) {
	int temp = x ^ y;
	return __builtin_popcount(temp);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int x, y;
	cin >> x >> y;
	cout << minBitsFlip_toConvert(x, y);

}
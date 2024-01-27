#include<bits/stdc++.h>
using namespace std;

int flipBits(int n) {
	int temp = n;
	//First make all bits 1
	n = n | (n >> 1);
	n = n | (n >> 2);
	n = n | (n >> 4);
	n = n | (n >> 8);
	n = n | (n >> 16);
	//now XOR for getting flip bits
	return temp ^ n;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	int n;
	cin >> n;
	cout << flipBits(n);

}
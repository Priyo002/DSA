#include<bits/stdc++.h>
using namespace std;

/*
Q :	Given an integer n, find the maximum power
	of two that is smaller than n
*/

//Method - 1
int max_powerof_2(int n) {
	int temp;
	while (n) {
		temp = n;
		n = n & (n - 1);
	}
	return temp;
}

//Method - 2
int max_powerof_2_2(int n) {
	//For 32 bits numbers
	n = n | (n >> 1);
	n = n | (n >> 2);
	n = n | (n >> 4);
	n = n | (n >> 8);
	n = n | (n >> 16);
	return (n + 1) / 2;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << max_powerof_2(n) << endl;
	cout << max_powerof_2_2(n);
}
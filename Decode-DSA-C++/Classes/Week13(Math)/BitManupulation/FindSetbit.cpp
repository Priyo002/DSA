#include<bits/stdc++.h>
using namespace std;

int set_bit(int n) {
	int cnt = 0;
	while (n > 0) {
		if (n % 2 != 0)
			cnt++;

		n /= 2;
	}
	return cnt;
}

// Brain Kernigler's Algorithm
int count_Setbit(int n) {
	int cnt = 0;
	while (n > 0) {
		n = n & (n - 1); //Eliminate one set bit in every itreation
		cnt++;
	}
	return cnt;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;

	cout << set_bit(n) << endl;

	//inbuilt function for finding set bits
	cout << __builtin_popcount(n) << endl;

	cout << count_Setbit(n);

}
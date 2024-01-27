#include<bits/stdc++.h>
using namespace std;

string str = "";
void kth(string s, int k, int n) {
	if (k == n) {
		str += s;
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {

		}
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n = 4;
	kth("01", 1, n);
	cout << str;
}
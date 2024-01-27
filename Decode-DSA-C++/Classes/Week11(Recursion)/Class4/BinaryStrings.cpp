#include<bits/stdc++.h>
using namespace std;

//No consecutive 1's

void binaryString(string s, int n) {
	if (s.size() == n) {
		cout << s << endl;
		return;
	}
	binaryString(s + '0', n);
	if (s.size() == 0) {
		binaryString(s + '1', n);
	}
	else if (s[s.size() - 1] != '1') {
		binaryString(s + '1', n);
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	binaryString("", n);

}
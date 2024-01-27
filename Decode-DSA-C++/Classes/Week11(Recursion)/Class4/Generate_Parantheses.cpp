#include<bits/stdc++.h>
using namespace std;

void generate(string s, int open, int close, int n) {
	if (close == n) {
		cout << s << endl;
		return;
	}
	if (open < n)
		generate(s + '(', open + 1, close, n);
	if (close < open)
		generate(s + ')', open, close + 1, n);

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n = 3;
	generate("", 0, 0, n);

}
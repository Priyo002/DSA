#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int id[128];
	id['v'] = 0;
	id['<'] = 1;
	id['^'] = 2;
	id['>'] = 3;
	char c1, c2;
	int T;
	cin >> c1 >> c2 >> T;
	T %= 4;
	if (T % 2 == 0)printf("undefined\n");
	else printf((id[c2] - id[c1] + 4) % 4 == T ? "cw" : "ccw");
	return 0;

}
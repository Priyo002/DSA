#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	double n;
	cin >> n;
	double k = log2(n);

	if (ceil(k) == floor(k)) {
		cout << "YES";
	}
	else cout << "NO";

}
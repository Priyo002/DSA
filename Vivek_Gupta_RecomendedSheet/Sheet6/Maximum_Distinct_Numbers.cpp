#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	vector<long long> v;
	v.push_back(1);
	v.push_back(3);
	while (v[v.size() - 1] <= n) {
		long long l = v.size() + 1;
		long long k = l + v[v.size() - 1];
		v.push_back(k);
	}
	cout << v.size() - 1;


}
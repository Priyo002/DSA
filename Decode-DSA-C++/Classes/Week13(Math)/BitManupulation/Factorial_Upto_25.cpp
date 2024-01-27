#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	int c = 1000000007;
	vector<long long> fact(26, 0);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); i++) {
		//fact[i] = fact[i-1] * i;
		fact[i] = ((fact[i - 1] % c) * (i % c)) % c;
	}

	int idx = 0;
	for (auto k : fact) {
		cout << idx << "!" << " = " << k << endl;
		idx++;
	}
}
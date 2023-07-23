#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long a, b, q;
	cin >> a >> b >> q;
	queue<long long> st;
	if (q == 1) {
		cout << a;
		return 0;
	}
	if (q == 2) {
		cout << b;
		return 0;
	}
	st.push(b);
	st.push(a ^ b);
	long long k = q - 3;
	while (k--) {
		long long t = st.front();
		st.pop();
		long long l = st.front();
		st.push(t ^ l);
	}
	cout << st.back();


}
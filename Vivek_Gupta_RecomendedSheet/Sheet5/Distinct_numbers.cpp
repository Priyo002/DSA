#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	set<int> st;
	while (n--) {
		int a;
		cin >> a;
		st.insert(a);
	}
	cout << st.size();


}
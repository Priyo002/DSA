#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	unordered_set<int> st;
	st.insert(1);
	st.insert(2);
	st.insert(1);
	st.insert(4);
	st.insert(8);
	st.insert(-1);
	for (auto it : st) {
		cout << it << " ";
	}
	if (st.find(2) != st.end()) cout << 1;

}
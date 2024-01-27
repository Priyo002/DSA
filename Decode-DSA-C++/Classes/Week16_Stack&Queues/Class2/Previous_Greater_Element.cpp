#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	vector<int> ans(n, -1);
	stack<int> st;
	st.push(arr[0]);
	for (int i = 1; i < n; i++) {
		while (st.size() && st.top() <= arr[i]) st.pop();
		if (st.size())
			ans[i] = st.top();
		st.push(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}
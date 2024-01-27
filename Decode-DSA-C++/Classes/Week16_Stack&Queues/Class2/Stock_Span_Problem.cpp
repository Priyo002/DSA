#include<bits/stdc++.h>
using namespace std;

/*
Input - 	[100,80,60,81,70,60,75,85]
Output - 	[-1,1,1,3,1,1,3,7]
*/

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {100, 80, 60, 81, 70, 60, 75, 85};
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	vector<int> ans(n, -1);
	stack<int> st;
	st.push(0);
	for (int i = 1; i < n; i++) {
		while (st.size() && arr[st.top()] <= arr[i]) st.pop();
		if (st.size())
			ans[i] = i - st.top();
		st.push(i);//Previous greater Index
	}
	ans[0] = 1;
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}
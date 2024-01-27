#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> arr = {3, -4, -7, 30, 7, -9, 2, 1, 6 , - 1}, ans;
	int k = 3;//window size
	//-4 -4 -7 -9 -9 -9 0 -1 {when (k=3)}
	queue<int> q;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < 0)
			q.push(i);
	}
	for (auto j : arr) {
		cout << j << " ";
	}
	cout << endl;

	int i = 0;
	while (i + k <= arr.size()) {
		while (q.size() && q.front() < i) q.pop();
		int x = q.front();
		if (q.size() == 0 || q.front() > i + k) ans.push_back(0);
		else ans.push_back(arr[q.front()]);
		i++;
	}
	for (auto j : ans) {
		cout << j << " ";
	}
}
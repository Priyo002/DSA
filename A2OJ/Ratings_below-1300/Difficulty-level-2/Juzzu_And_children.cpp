#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> arr(n);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i);
		cin >> arr[i];
	}
	while (q.size() != 1) {
		while (q.size() > 1 && arr[q.front()] <= m) {
			q.pop();
		}
		arr[q.front()] -= m;
		q.push(q.front());
		q.pop();
	}
	cout << q.front() + 1;

}
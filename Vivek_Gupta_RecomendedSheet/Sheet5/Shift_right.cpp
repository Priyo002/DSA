#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, x;
	cin >> n >> x;
	deque<int> q;
	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		q.push_back(a);
	}
	while (x--) {
		q.push_front(q.back());
		q.pop_back();
	}
	while (q.size()) {
		cout << q.front() << " ";
		q.pop_front();
	}

}
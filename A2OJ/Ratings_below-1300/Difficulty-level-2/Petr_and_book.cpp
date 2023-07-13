#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < 7; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}
	int sum = 0;
	int cnt = 0;
	while (sum < n) {
		sum += q.front();
		q.push(q.front());
		q.pop();
		cnt++;
	}
	if (cnt > 7)
		if (cnt % 7 == 0) {
			cout << 7;
		}
		else
			cout << cnt % 7;
	else cout << cnt;
}
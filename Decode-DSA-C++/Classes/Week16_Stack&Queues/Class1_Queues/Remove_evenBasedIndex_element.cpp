#include<bits/stdc++.h>
using namespace std;

void display(queue<int> &q) {
	int size = q.size();
	while (size--) {
		cout << q.front() << " ";
		q.push(q.front());
		q.pop();
	}
	cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);

	int n = q.size();

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) q.pop();
		else {
			q.push(q.front());
			q.pop();
		}
	}

	display(q);

}
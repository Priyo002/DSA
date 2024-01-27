#include<bits/stdc++.h>
using namespace std;

void display(queue<int> &q) {
	int n = q.size();
	while (n--) {
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
	for (int i = 1; i <= 10; i++) {
		q.push(i);
	}
	display(q);

	int k = 3;

	int temp = q.size() - k;
	while (temp--) {
		q.push(q.front());
		q.pop();
	}
	while (k--) {
		q.pop();
	}
	display(q);

}
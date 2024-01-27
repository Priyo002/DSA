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

void reverse(queue<int> &q) {
	stack<int> st;
	while (q.size()) {
		st.push(q.front());
		q.pop();
	}
	while (st.size()) {
		q.push(st.top());
		st.pop();
	}
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

	display(q);
	reverse(q);
	display(q);

}
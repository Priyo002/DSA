#include<bits/stdc++.h>
using namespace std;

/*
Interleave 1st half with 2nd half
(do this only one stack) [Even length]
*/

void display(queue<int> &q) {
	int n = q.size();
	while (n--) {
		cout << q.front() << " ";
		q.push(q.front());
		q.pop();
	}
	cout << endl;
}

void reorder(queue<int> &q) {
	int n = q.size() / 2;
	int k = n;
	stack<int> st;
	while (n--) {
		st.push(q.front());
		q.pop();
	}
	while (st.size()) {
		q.push(st.top());
		st.pop();
	}
	while (k--) {
		st.push(q.front());
		q.pop();
	}
	while (st.size()) {
		q.push(st.top());
		st.pop();
		q.push(q.front());
		q.pop();
	}
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
	//[1 2 3 4 5 6 7 8]
	//[1 5 2 6 3 7 4 8]
	queue<int> q;
	for (int i = 1; i <= 8; i++) {
		q.push(i);
	}
	display(q);

	reorder(q);
	display(q);


}
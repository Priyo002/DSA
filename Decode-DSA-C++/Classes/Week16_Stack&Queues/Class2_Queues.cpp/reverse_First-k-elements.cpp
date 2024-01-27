#include<bits/stdc++.h>
using namespace std;

void display(queue<int>& q) {
	int n = q.size();
	while (n--) {
		int x = q.front();
		cout << x << " ";
		q.pop();
		q.push(x);
	}
	cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	queue<int> a;
	for (int i = 1; i <= 10; i++) {
		a.push(i);
	}
	display(a);

	int k = 10;
	int n = a.size() - k;
	stack<int> st;

	while (k--) {
		st.push(a.front());
		a.pop();
	}
	while (st.size()) {
		a.push(st.top());
		st.pop();
	}
	while (n--) {
		a.push(a.front());
		a.pop();
	}

	display(a);

}
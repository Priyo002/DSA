#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s) {
	while (s.size()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void pushAtidx(stack<int> &st, int idx, int val) {
	stack<int> temp;
	int n = st.size() - idx - 1;
	while (n--) {
		temp.push(st.top());
		st.pop();
	}
	st.push(val);
	while (temp.size()) {
		st.push(temp.top());
		temp.pop();
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	print(st);
	pushAtidx(st, 2, 90);
	print(st);
}
#include<bits/stdc++.h>
using namespace std;

void displayRev(stack<int>& st) {
	if (st.size() == 0) return;
	int x = st.top();
	cout << x << " ";
	st.pop();
	displayRev(st);
	st.push(x);
}

void display(stack<int>& st) {
	if (st.size() == 0) return;
	int x = st.top();
	st.pop();
	display(st);
	cout << x << " ";
	st.push(x);
}

void pushAtbottom(stack<int> &st, int val) {
	if (st.size() == 0) {
		st.push(val);
		return;
	}
	int x = st.top();
	st.pop();
	pushAtbottom(st, val);
	st.push(x);
}

void reverse(stack<int> &st) {
	if (st.size() == 1) return;
	int x = st.top();
	st.pop();
	reverse(st);
	pushAtbottom(st, x);
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
	// display(st);
	// cout << endl;
	// pushAtbottom(st, -10);
	reverse(st);
	displayRev(st);


}
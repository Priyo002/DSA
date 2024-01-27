#include<bits/stdc++.h>
using namespace std;

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
	stack<int> temp;
	while (st.size()) {
		cout << st.top() << " ";
		temp.push(st.top());
		st.pop();
	}
	cout << endl;
	while (temp.size()) {
		cout << temp.top() << " ";
		st.push(temp.top());
		temp.pop();
	}
	cout << endl;
	while (st.size()) {
		cout << st.top() << " ";
		temp.push(st.top());
		st.pop();
	}


}
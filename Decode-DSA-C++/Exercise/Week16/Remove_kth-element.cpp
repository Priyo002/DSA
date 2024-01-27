#include<bits/stdc++.h>
using namespace std;

void display(stack<int> s1) {
	while (s1.size()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	stack<int> s1;
	for (int i = 0; i <= 10; i++) {
		s1.push(i);
	}
	display(s1);
	int idx = 3;//element to be deleted
	stack<int> s2;
	while (idx--) {
		s2.push(s1.top());
		s1.pop();
	}
	display(s2);
	s1.pop();
	while (s2.size()) {
		s1.push(s2.top());
		s2.pop();
	}
	display(s1);
}
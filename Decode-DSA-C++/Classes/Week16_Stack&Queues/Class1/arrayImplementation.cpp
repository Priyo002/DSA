#include<bits/stdc++.h>
using namespace std;

class Stack {
public:
	int arr[5];//Use vector for unlimited size
	int idx;
	Stack() {
		idx = -1;
	}
	void push(int val) {
		if (idx == sizeof(arr) / sizeof(int) - 1) {
			cout << "Stack is full";
			return;
		}
		idx++;
		arr[idx] = val;
	}
	void pop() {
		if (idx == -1) {
			cout << "Stack is empty";
			return;
		}
		idx--;
	}
	int top() {
		return arr[idx];
	}
	int size() {
		return idx + 1;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	cout << st.size() << endl;
	st.pop();
	cout << st.size() << endl;
}

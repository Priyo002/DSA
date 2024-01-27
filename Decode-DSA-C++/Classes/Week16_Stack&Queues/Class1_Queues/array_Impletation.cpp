#include<bits/stdc++.h>
using namespace std;

class Queue {
public:
	int f;
	int b;
	int s;
	vector<int>arr;
	Queue(int val) {
		f = 0;
		b = 0;
		vector<int> v(val);
		arr = v;
		s = 0;
	}

	void push(int val) {
		if (b == arr.size()) {
			cout << "Queue is full!" << endl;
			return;
		}
		arr[b++] = val;
		s++;
	}
	void pop() {
		if (s == 0) {
			cout << "Queue is Empty!" << endl;
			return;
		}
		f++;
		s--;
	}
	int front() {
		if (s == 0) {
			cout << "Queue is Empty!" << endl;
			return -1;
		}
		return arr[f];
	}
	int back() {
		if (s == 0) {
			cout << "Queue is Empty!" << endl;
			return  -1;
		}
		return arr[b - 1];
	}

	int size() {
		return s;
	}
	bool empty() {
		if (s == 0) return true;
		else return false;
	}
	void display() {
		for (int i = f; i < b; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Queue q(5);
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);

	q.display();
	q.pop();
	q.display();

}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void init() {
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void solve() {

}

int main() {

	init();

	int arr[] = {9, 6, 1, 19, 3, 2, 8, 12, 5};
	int n = sizeof(arr) / sizeof(int);
	vector<int> v = {9, 6, 1, 19, 3, 2, 8, 12, 5};

	priority_queue<int> maxpq;//By default it is MaxHeap
	priority_queue<int, vector<int>, greater<int>> pq; //MinHeap

	//Minheap using vector
	priority_queue<int, vector<int>, greater<int>> minHp(v.begin(), v.end());

	//Maxheap usign array
	priority_queue<int> maxhp(arr, arr + n);

	pq.push(3);
	pq.push(4);
	pq.push(11);
	pq.push(9);
	pq.push(14);
	pq.push(-1);
	pq.push(30);
	pq.push(44);
	pq.push(50);

	cout << pq.top() << endl;
	cout << minHp.top() << endl;
	cout << maxhp.top();

	return 0;

}
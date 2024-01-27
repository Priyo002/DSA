#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(30);
	cout << dq.front();

}
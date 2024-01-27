#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int mod = 1e9 + 7;

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

bool cmp(int a, int b) {
	return a > b;
}

class compare {
public:
	bool operator()(int a, int b) {
		return a > b;

	}
};

void display(priority_queue<int, vector<int>, compare> p) {

	while (!p.empty()) {
		cout << p.top() << " ";
		p.pop();
	}
}

int main() {

	init();

	vector<int> v = {5, 4, 6, -1, 0, 3, 2};
	//priority_queue<int,vector<int>, function<bool(int,int)> > pq(cmp);
	priority_queue<int, vector<int>, compare> pq (v.begin(), v.end());
	display(pq);
	return 0;


}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

}

int getmedian(priority_queue<int>& left, priority_queue<int, vector<int>, greater<int>>& right) {
	int ts = left.size() + right.size();
	if (ts % 2 != 0) {
		return right.top();
	}
	else return left.top();

}


bool isBalanced(priority_queue<int>& left, priority_queue<int, vector<int>, greater<int>>& right) {
	int l = left.size();
	int k = right.size();
	return (l == k) || (l + 1 == k);
}

void removeMedian(priority_queue<int>& left, priority_queue<int, vector<int>, greater<int>>& right) {
	if (left.size() == right.size()) {
		left.pop();
	}
	else right.pop();
}

void solve() {

	int t;
	cin >> t;
	while (t--) {
		priority_queue<int> left;//Maxheap
		priority_queue<int, vector<int>, greater<int>> right; //Minheap
		while (true) {
			int n;
			cin >> n;
			if (n == 0) break ;
			else if ((left.size() + right.size()) == 0) {
				right.push(n);
			}
			else if (n == -1) {
				cout << getmedian(left, right) << endl;
				//remove the median
				removeMedian(left, right);
			}
			else {
				int med = getmedian(left, right);
				if (n > med) {
					right.push(n);
					if (!isBalanced(left, right)) {
						int curr = right.top();
						right.pop();
						left.push(curr);
					}
				}
				else {
					left.push(n);
					if (!isBalanced(left, right)) {
						int curr = left.top();
						left.pop();
						right.push(curr);
					}
				}
			}
		}
	}
}

int main() {

	init();

	solve();

}
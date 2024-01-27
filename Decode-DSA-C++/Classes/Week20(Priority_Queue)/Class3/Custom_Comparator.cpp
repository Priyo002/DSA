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
	//return true; pick a (first argument)
	//return false; pick b (second argument)
}

int main() {

	init();

	vector<int> v = {5, 4, 6, -1, 0, 3, 2};
	sort(v.begin(), v.end(), cmp);
	for (auto x : v) cout << x << " ";

	return 0;

}
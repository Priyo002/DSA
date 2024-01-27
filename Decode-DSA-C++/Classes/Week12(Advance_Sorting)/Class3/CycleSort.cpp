#include<bits/stdc++.h>
using namespace std;

//only for array [1,n] or [0,n]

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> v = {4, 1, 6, 5, 3, 2};

	int i = 0;
	while (i < v.size()) {
		int correctIdx = v[i] - 1;
		if (i == correctIdx) i++;
		else swap(v[i], v[correctIdx]);
	}

	for (auto i : v) {
		cout << i << " ";
	}

}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<vector<int>> v = {{9, 2, 3}, {7, 4, 5}};
	sort(v[0].begin(), v[0].end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

}
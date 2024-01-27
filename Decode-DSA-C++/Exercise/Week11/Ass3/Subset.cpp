#include<bits/stdc++.h>
using namespace std;

void subset(vector<vector<int>> &ans, vector<int> temp, vector<int> &v, int idx) {
	if (idx == v.size()) {
		ans.push_back(temp);
		return;
	}
	subset(ans, temp, v, idx + 1);
	temp.push_back(v[idx]);
	subset(ans, temp, v, idx + 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> v = {1, 2, 3, 4};
	vector<vector<int>> ans;
	vector<int> temp;
	subset(ans, temp, v, 0);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}
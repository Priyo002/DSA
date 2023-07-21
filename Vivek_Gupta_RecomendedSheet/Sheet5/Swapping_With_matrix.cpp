#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, x, y;
	cin >> n >> x >> y;
	vector<vector<int>> arr;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		arr.push_back(v);
	}

	for (int j = 0; j < n; j++) {
		swap(arr[x - 1][j], arr[y - 1][j]);
	}
	for (int i = 0; i < n; i++) {
		swap(arr[i][x - 1], arr[i][y - 1]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}



}
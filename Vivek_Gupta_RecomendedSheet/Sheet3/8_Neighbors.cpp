#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	char arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int x, y;
	cin >> x >> y;
	x = x - 1;
	y = y - 1;
	if (x < n  && arr[x + 1][y] == '.') {
		cout << "no";
		return 0;
	}
	else if (y < m && arr[x][y + 1] == '.') {
		cout << "no";
		return 0;
	}
	else if (y > 0 && arr[x][y - 1] == '.') {
		cout << "no";
		return 0;
	}
	else if (x > 0 && arr[x - 1][y] == '.') {
		cout << "no";
		return 0;
	}
	else if (x > 0 && y > 0 && arr[x - 1][y - 1] == '.') {
		cout << "no";
		return 0;
	}
	else if (x > 0 && y < m  && arr[x - 1][y + 1] == '.') {
		cout << "no";
		return 0;
	}
	else if (y > 0 && x < n  && arr[x + 1][y - 1] == '.') {
		cout << "no";
		return 0;
	}
	else if ((y < m ) && (x < n ) && (arr[x + 1][y + 1] == '.')) {
		cout << "no";
		return 0;
	}
	else
		cout << "yes";



}
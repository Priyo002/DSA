#include<bits/stdc++.h>
using namespace std;



int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[3][3], ans[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			ans[i][j] = 1;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] % 2 != 0) {
				if (ans[i][j] == 1) ans[i][j] = 0;
				else ans[i][j] = 1;

				if (ans[i][j + 1] == 1 && j < 2)
					ans[i][j + 1] = 0;
				else if (ans[i][j + 1] == 0 && j < 2)
					ans[i][j + 1] = 1;

				if (ans[i + 1][j] == 1 && i < 2)
					ans[i + 1][j] = 0;
				else if (ans[i + 1][j] == 0 && i < 2)
					ans[i + 1][j] = 1;

				if (ans[i - 1][j] == 1 && i > 0)
					ans[i - 1][j] = 0;
				else if (ans[i - 1][j] == 0 && i > 0)
					ans[i - 1][j] = 1;

				if (ans[i][j - 1] == 1 && j > 0)
					ans[i][j - 1] = 0;
				else if (ans[i][j - 1] == 0 && j > 0)
					ans[i][j - 1] = 1;

			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ans[i][j] ;
		}
		cout << endl;
	}

}
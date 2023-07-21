#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		char arr[8][8];
		int idx1 = -1, idx2 = -1;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> arr[i][j];
				if (arr[i][j] != '.' && idx1 == -1) {
					idx1 = i;
					idx2 = j;
				}
			}
		}

		string str = "";
		for (int i = idx1; i < 8; i++) {
			if (arr[i][idx2] != '.')
				str.push_back(arr[i][idx2]);
		}
		cout << str << endl;
	}

}
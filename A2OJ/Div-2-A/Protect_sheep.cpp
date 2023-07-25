#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int r, c;
	cin >> r >> c;

	char s[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> s[i][j];
			if (s[i][j] == '.') {
				s[i][j] = 'D';
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (s[i][j] == 'S') {
				if (i > 0 && s[i - 1][j] == 'W') {
					cout << "No";
					return 0;
				}
				else if (i < r - 1 && s[i + 1][j] == 'W') {
					cout << "No";
					return 0;
				}
				else if (j > 0 && s[i][j - 1] == 'W') {
					cout << "No";
					return 0;
				}
				else if (j < c - 1 && s[i][j + 1] == 'W') {
					cout << "No";
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << s[i][j];
		}
		cout << endl;
	}
}

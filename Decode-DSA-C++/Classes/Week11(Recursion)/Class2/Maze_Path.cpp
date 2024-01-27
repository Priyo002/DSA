#include<bits/stdc++.h>
using namespace std;

/*
2-D Matrix (star from starting index)
(reaching to the Destination which is at last index)
right and down only allowed

sr -> staring row;
sc -> starting column;
er -> ending row;
ec -> ending column;
*/

void printPath(int sr, int sc, int er, int ec, string s) {
	if (sr > er || sc > ec) return;
	if (sr == er && sc == ec) {
		cout << s << endl;
		return;
	}
	printPath(sr, sc + 1, er, ec, s + 'R');
	printPath(sr + 1, sc, er, ec, s + 'D');
}

int maze2(int row, int col) {
	if (row < 1 || col < 1) return 0;
	if (row == 1 && col == 1) return 1;
	int rightways = maze2(row, col - 1);
	int downways = maze2(row - 1, col);
	return rightways + downways;
}

int maze(int sr, int sc, int er, int ec) {
	if (sr > er || sc > ec) return 0;
	if (sr == er && sc == ec) return 1;
	int rightways = maze(sr, sc + 1, er, ec);
	int downways = maze(sr + 1, sc, er, ec);
	return rightways + downways;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	cout << maze(1, 1, 3, 3) << endl;
	cout << maze2(3, 3) << endl;
	printPath(1, 1, 3, 3, "");
}
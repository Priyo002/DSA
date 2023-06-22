#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	float x, y;
	cin >> x >> y;

	if (x == 0 && y == 0) {
		cout << "Origem";
	}
	else if (y == 0) {
		cout << "Eixo X";
	}
	else if (x == 0) {
		cout << "Eixo Y";
	}
	else if (x < 0 && y < 0) {
		cout << "Q3";
	}
	else if (x > 0 && y > 0) {
		cout << "Q1";
	}
	else if (x < 0 && y > 0) {
		cout << "Q2";
	}
	else if (x > 0 && y < 0) {
		cout << "Q4";
	}
}
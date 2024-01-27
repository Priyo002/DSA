#include<bits/stdc++.h>
using namespace std;
/*
A -> source
B -> helper
C -> destination
hanoi(source, helper, destination);
*/

void hanoi(int n, char a, char b, char c) {
	if (n == 0) return;
	hanoi(n - 1, a, c, b);
	cout << a << "->" << c << endl;
	hanoi(n - 1, b, a, c);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');

}
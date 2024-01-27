#include<bits/stdc++.h>
using namespace std;

/*
work -> Pre
call1
work -> IN
call2
work -> Post
*/

void pip(int n) {
	if (n == 0) return;
	cout << "Pre " << n << endl;
	pip(n - 1);
	cout << "In " << n << endl;
	pip(n - 1);
	cout << "Post " << n << endl;

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif


	pip(3);
}
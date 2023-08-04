#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vii for(int i=0;i<n;i++)


void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	vii cin >> v[i];
	if (n % 2 == 0) {
		cout << "NO";
	}
	else if ((v[0] % 2 == 0) || (v[n - 1] % 2 == 0)) {
		cout << "NO";
	}
	else cout << "YES";

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	solve();
}
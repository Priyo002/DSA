#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<int> freq(m + 1, 0);
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}
	for (int i = 1; i < freq.size(); i++) {
		cout << freq[i] << endl;
	}


}
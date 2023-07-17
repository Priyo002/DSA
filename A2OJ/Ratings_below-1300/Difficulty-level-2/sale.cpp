#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int sum = 0;
	vector<int> arr(n);
	vector<int> neg;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < 0)
			neg.push_back(arr[i]);

	}
	sort(neg.begin(), neg.end());
	int cnt = 0;
	for (int i = 0; i < neg.size(); i++) {
		if (cnt < m)
			sum += (-neg[i]);
		cnt++;
	}
	cout << abs(sum);

}
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
		int n;
		cin >> n;
		set<int> st;
		int maxi = INT_MIN;
		vector<int> arr(n + 1, 0);
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			if (arr[k] == 0) {
				arr[k]++;
				st.insert(k);
			}
			else if (arr[k] == 1) {
				arr[k]--;
				st.erase(st.find(k));
			}
			int t1 = st.size();
			if (t1 > maxi) maxi = t1;
		}
		cout << maxi << endl;
	}

}
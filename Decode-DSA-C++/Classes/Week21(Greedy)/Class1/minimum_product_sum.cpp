#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define inf 1e18
const int mod = 1e9 + 7;

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

}

int minProduct(vector<int>&arr) {
	int cn = 0, cz = 0, cp = 0;
	int prod_pos = 1;
	int prod_neg = 1;
	int largest_neg = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < 0) {
			cn++;
			prod_neg *= arr[i];
			largest_neg = max(largest_neg, arr[i]);
		}
		else if (arr[i] == 0) cz++;
		else {
			cp++;
			prod_pos *= arr[i];
		}
	}
	if (cn == 0) {
		if (cz > 0) return 0;
		else {
			return *min_element(arr.begin(), arr.end());
		}
	}
	else {
		if (cn % 2 == 0) {
			return (prod_neg / largest_neg) * prod_pos;
		}
		else {
			return prod_pos * prod_neg;
		}
	}
}

int32_t main() {

	init();
	vector<int> arr = { -2, -3, 1, 4, -2};
	cout << minProduct(arr);

}
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


//Sorting by value by weight ratio
bool cmp(pair<int, int>&p1, pair<int, int>&p2) {
	//pair<int,int> first->value , second->weight;
	double r1 = (p1.first * 1.0) / (p1.second * 1.0);
	double r2 = (p2.first * 1.0) / (p2.second * 1.0);
	return r1 > r2;
}
/*
 * T.C. : O(nlogn)
 * S.C. : (sorting algo)
*/
double fractional_knapsack(vector<int>&profit, vector<int>&weights, int n, int w) {
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back({profit[i], weights[i]});
	}
	sort(arr.begin(), arr.end(), cmp);
	double res = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].second <= w) {
			res += arr[i].first;
			w -= arr[i].second;
		}
		else {
			res += (arr[i].first * 1.0) / (arr[i].second * 1.0) * w;
			w = 0;
			break;
		}
	}
	return res;
}

int32_t main() {

	init();

	vector<int> profit = {60, 100, 120};
	vector<int> weights = {10, 20, 30};
	int w = 50;//knapsack capacity
	int n = 3;//number of elements
	cout << fractional_knapsack(profit, weights, n, w);

}
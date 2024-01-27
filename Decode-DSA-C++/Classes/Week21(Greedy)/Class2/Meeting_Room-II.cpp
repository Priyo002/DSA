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

/* LeetCode : 253
 *
 * Given an array of meeting time intervals consisting of
 * start and end times [[s1,e1],[s2,e2],...] (si < ei),
 * find the minimum number of conference rooms required.)
 *
 * Input :
 * Intervals =
 * [[0,30],[5,10],[15,20]]
 * Output : 2
 */

int minMeetingRoom(vector<vector<int>>& Intervals) {
	vector<int> start, ending;
	for (auto el : Intervals) {
		start.pb(el[0]);
		ending.pb(el[1]);
	}
	sort(start.begin(), start.end());
	sort(ending.begin(), ending.end());
	int ans = 0;
	int rooms = 0;
	int i = 0, j = 0;
	while (i < start.size()) {
		if (start[i] < ending[j]) {
			rooms++;
			ans = max(ans, rooms);
			i++;
		}
		else if (start[i] > ending[j]) {
			rooms--;
			j++;
		}
		else {
			i++;
			j++;
		}
	}
	return ans;
}

int32_t main() {

	init();

	vector<vector<int>> v =  {{0, 30}, {5, 10}, {15, 20}};

	cout << minMeetingRoom(v);


}
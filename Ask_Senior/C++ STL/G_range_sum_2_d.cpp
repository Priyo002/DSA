#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;
const long long INF = 1e18;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void solve() {

	int n,m,q;
	cin >> n >> m >> q;

	vector<vector<int>> arr(n+1,vector<int>(m+1,0));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> arr[i][j];
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j] += (arr[i-1][j] + arr[i][j-1]-arr[i-1][j-1]);
		}
	}

	while(q--){
		int x1,y1,x2,y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int total = arr[x2][y2];

		total = (total - arr[x1-1][y2]);
		total = (total - arr[x2][y1-1]);
		total = (total + arr[x1-1][y1-1]);


		cout << total << endl;
	}

	
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int _t = 1;
	//cin >> _t;
	while (_t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9+7;
const long long INF = 1e18;

void init(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n,m;
int dp[13][13][(1<<13)-1];

int f(int row,int col,int mask){

    if(row == n) return ((1<<m) - 1) == mask;

    if(dp[row][col][mask]!=-1) return dp[row][col][mask];

    int currBit = ((mask>>col)&1);
    int prevBit = -1;
    if(col){
        prevBit = ((mask>>(col-1))&1);
    }

    int newRow, newCol;
    if(col == m - 1){
        newRow = row + 1;
        newCol = 0;
    }
    else{
        newRow = row;
        newCol = col + 1;
    }

    int ans = 0;
    
    // upper one is empty
    if(row!=0 && currBit == 0){
        int newMask = (mask|(1<<col));
        ans += f(newRow,newCol,newMask);
    }
    // left one is empty
    else if(col && prevBit == 0){
        int newMask = (mask|(1<<col)|(1<<(col-1)));
        ans += f(newRow,newCol,newMask);
        newMask = (mask&(~(1<<col))); // setting the current bit to 0
        ans += f(newRow,newCol,newMask);
    }
    // both occupied
    else{
        int newMask = (mask&(~(1<<col))); // setting the current bit to 0
        ans += f(newRow,newCol,newMask);
    }

    ans %= mod;
    return dp[row][col][mask] = ans;
}

void solve(){
    cin >> n >> m;

    memset(dp,-1,sizeof(dp));

    cout << f(0,0,0) << endl;
}

int32_t main(){
	
	init();
	//clock_t time_req;
	//time_req = clock();

	int _t = 1;
	//cin >> _t;
	while(_t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
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
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

int n;
vector<vector<int>> cost;


int f(int i,int k){
    if(i==n){
        if(k==0) return 0;
        else return 1e18;
    }

    int ans = 1e18;

    for(int p=0;p<=k;p++){
        if(cost[i][p]==1e18) continue;
        ans = min(ans,cost[i][p]+f(i+1,k-p));
    }
    
    return ans;
}

void solve(){
    int k;
    cin >> n >> k;

    cost.clear();
    cost.resize(n+1,vector<int>(1000,1e18));

    for(int i=0;i<n;i++){
        int row,col;
        cin >> row >> col;
        cost[i][0] = 0;
        int points = 1;
        int mn = min(row,col), mx = max(row,col);
        while(mn>0 && mx>0){
            cost[i][points] = cost[i][points-1] + mn;
            points++;
            mx--;
            int temp = mn;
            mn = min(mn,mx);
            mx = max(mx,temp);
        }
        cost[i][points-1]++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    cout << f(0,k) << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
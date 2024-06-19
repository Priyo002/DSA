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

void solve(){
    int n,m;
    cin >> n >> m;

    vector<string> grid;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;

        grid.push_back(s);
    }

    int top = -1, bottom = -1, left = -1, right = -1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#'){
                top = i+1;
                break;
            }
        }
        if(top!=-1) break;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#'){
                bottom = i+1;
                break;
            }
        }
        if(bottom!=-1) break;
    }

    int x = (top+bottom+2-1)/2;

    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(grid[i][j]=='#'){
                left = j+1;
                break;
            }
        }
        if(left!=-1) break;
    }

     for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(grid[i][j]=='#'){
                right = j+1;
                break;
            }
        }
        if(right!=-1) break;
    }

    int y = (right+left+2-1)/2;

    cout << x << " " << y << endl;
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
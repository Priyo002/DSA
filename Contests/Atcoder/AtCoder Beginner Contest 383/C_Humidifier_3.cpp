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

void solve(){
    int n,m,d;
    cin >> n >> m >> d;

    vector<string> arr(n);
    queue<pair<int,int>> qu;
    vector<vector<int>> dist(n,vector<int>(m,1e9));

    for(int i=0;i<n;i++){
        cin >> arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j] == 'H'){
                qu.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    while(qu.size()){
        int cnt = qu.size();
        while(cnt--){
            auto curr = qu.front();
            qu.pop();

            for(int i=0;i<4;i++){
                int nx = curr.first + dir[i][0];
                int ny = curr.second + dir[i][1];
                if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny] == '.' && dist[nx][ny] == 1e9){
                    dist[nx][ny] = 1 + dist[curr.first][curr.second];
                    qu.push({nx,ny});
                }
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans += (dist[i][j]<=d);
        }
    }
    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
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

vector<string> graph;
vector<vector<int>> visited;
int n,m;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int i,int j){
    visited[i][j] = 1;
    for(int d=0;d<4;d++){
        int x = i+dir[d][0];
        int y = j+dir[d][1];
        if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && graph[x][y]=='.'){
            dfs(x,y);
        }
    }
}

void solve(){
    cin >> n >> m;

    graph.clear();
    visited.clear();
    visited.resize(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        graph.push_back(s);
    }

    int cc = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && graph[i][j]=='.'){
                cc++;
                dfs(i,j);
            }
        }
    }
    cout << cc << endl;
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
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

using pp = pair<int,int>;

int n,m;
vector<vector<int>> dist;
vector<vector<char>> parDir;
vector<vector<pp>> par;
vector<string> grid;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool check(int x,int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs(){
    queue<pp> qu;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M'){
                qu.push({i,j});
                dist[i][j] = 0;
            }
        }
    }
    while(qu.size()){
        int cnt = qu.size();
        while(cnt--){
            auto curr = qu.front();
            qu.pop();

            for(int d=0;d<4;d++){
                int x = curr.first + dir[d][0];
                int y = curr.second + dir[d][1];
                if(check(x,y) && dist[x][y]>1+dist[curr.first][curr.second] && grid[x][y]!='#' && grid[x][y]!='A'){
                    dist[x][y] = 1+dist[curr.first][curr.second];
                    qu.push({x,y});
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                qu.push({i,j});
                dist[i][j] = 0;
                parDir[i][j] = 'S';
            }
        }
    }

    while(qu.size()){
        int cnt = qu.size();
        while(cnt--){
            auto curr = qu.front();
            qu.pop();

            for(int d=0;d<4;d++){
                int x = curr.first + dir[d][0];
                int y = curr.second + dir[d][1];
                if(check(x,y) && dist[x][y]>1+dist[curr.first][curr.second] && grid[x][y]!='#' && grid[x][y]!='M'){
                    dist[x][y] = 1+dist[curr.first][curr.second];
                    par[x][y] = {curr.first,curr.second};
                    if(dir[d][0]==0){
                        if(dir[d][1]==1) parDir[x][y] = 'R';
                        else if(dir[d][1]==-1) parDir[x][y] = 'L';
                    }
                    else if(dir[d][1]==0){
                        if(dir[d][0]==1) parDir[x][y] = 'D';
                        else if(dir[d][0]==-1) parDir[x][y] = 'U';
                    }
                    qu.push({x,y});
                }
            }
        }
    }
}

void solve(){
    cin >> n >> m;

    grid.clear();
    grid.resize(n);

    dist.clear();
    dist.resize(n,vector<int>(m,1e18));

    par.clear();
    par.resize(n,vector<pp>(m,{-1,-1}));

    parDir.clear();
    parDir.resize(n,vector<char>(m,'?'));

    for(int i=0;i<n;i++) cin >> grid[i];

    bfs();

    string ans = "";
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || j==0 || i==n-1 || j==m-1) && parDir[i][j]!='?'){
                flag = true;
                int currX = i, currY = j;
                while(currX!=-1 && currY!=-1){
                    ans += parDir[currX][currY];
                    int px = par[currX][currY].first;
                    int py = par[currX][currY].second;
                    currX = px, currY = py;
                }
                break;
            }
            
        }
        if(flag) break;
    }
    if(ans.size()==0){
        cout << "NO" ;
        return;
    }
    ans.pop_back();
    cout << "YES" << endl;
    cout << ans.size() << endl;
    reverse(ans.begin(),ans.end());
    cout << ans;
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
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

int srcX,srcY,destX,destY;
int n,m;
vector<string> grid;
vector<vector<int>> visited;
vector<vector<pair<int,int>>> par;
map<pair<int,int>,char> mp;

void mark(int nx,int ny,int x,int y){
    if(x==nx){
        if(ny+1==y){
            mp[{nx,ny}] = 'L';
        }
        else{
            mp[{nx,ny}] = 'R';
        }
    }
    else{
        if(nx+1==x){
            mp[{nx,ny}] = 'U';
        }
        else{
            mp[{nx,ny}] = 'D';
        }
    }
}

void bfs(){

    mp.clear();
    visited.clear();
    par.clear();

    visited.resize(n,vector<int>(m,0));
    par.resize(n,vector<pair<int,int>>(m,{-1,-1}));

    queue<pair<int,int>> qu;

    qu.push({srcX,srcY});
    visited[srcX][srcY] = 1;

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    while(qu.size()){
        auto curr = qu.front();
        qu.pop();

        int x = curr.first, y = curr.second;

        if(x==destX && y==destY) return;

        for(int d=0;d<4;d++){
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && (grid[nx][ny]=='.' || grid[nx][ny]=='B') && !visited[nx][ny]){
                par[nx][ny] = {x,y};
                visited[nx][ny] = 1;
                mark(nx,ny,x,y);
                qu.push({nx,ny});
            }
        }
    }
}

void solve(){
    cin >> n >> m;

    grid.clear();

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                srcX = i;
                srcY = j;
            }
            if(grid[i][j]=='B'){
                destX = i;
                destY = j;
            }
        }
    }

    bfs();

    if(visited[destX][destY]){
        cout << "YES" << endl;
        string s = "";
        int x = destX, y = destY;
        while(x!=-1 && y!=-1){
            s += mp[{x,y}];
            int nx = par[x][y].first;
            int ny = par[x][y].second;
            x = nx, y = ny;
        }
        s.pop_back();
        reverse(s.begin(),s.end());
        cout << s.size() << endl;
        cout << s << endl;
    }
    else{
        cout << "NO" << endl;
    }

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
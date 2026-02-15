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

int n, k, cnt;
vector<string> grid;
vector<vector<int>> visited, color, pref1, pref2;
vector<int> A, a;
map<int,int> sizee;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int r, int c, int col){
    visited[r][c] = true;
    color[r][c] = col;
    cnt++;
    for(int d=0;d<4;d++){
        int nr = r + dir[d][0];
        int nc = c + dir[d][1];
        if(r<0 || r>n || c<0 || c>n || visited[r][c] || grid[r][c] == 'X') continue;
        dfs(nr, nc, col);
    }
}

void build(){

    pref1.assign(n, vector<int>());
    pref2.assign(n, vector<int>());

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            cnt += (grid[i][j] == 'X');
            if(j-k>=0){
                cnt -= (grid[i][j-k] == 'X');
            }
            if(j>=k-1){
                pref1[i].push_back(cnt);
            }
        }
    }

    a.clear();
    for(int j=0;j<pref1[0].size();j++){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += pref1[i][j];
            if(i-k>=0){
                sum -= pref1[i][j-k];
            }
            if(i>=k-1){
                a.push_back(sum);
            }
        }
    }

    int len = k+2;
    for(int i=0;i<n;i++){
        int sum = 0;
        map<int,int> freq;
        for(int j=0;j<n;j++){
            if(grid[i][j] == '.'){
                freq[color[i][j]]++;
                if(freq[color[i][j]] == 1){
                    sum += sizee[color[i][j]];
                }
            }
            if(j-len>=0 && grid[i][j-len] == '.'){
                freq[color[i][j-len]]--;
                if(freq[color[i][j-len]] == 0){
                    freq.erase(color[i][j-len]);
                    sum -= sizee[color[i][j-len]];
                }
            }
            if(i>=len-1){
                pref2[i].push_back(sum);
            }
        }
    }

    A.clear();
    for(int j=0;j<pref2[0].size();j++){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += pref2[i][j];
            if(i-len>=0){
                sum -= pref2[i][j-len];
            }
            if(i>=len-1){
                A.push_back(sum);
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    grid.assign(n, "");
    for(int i=0;i<n;i++){
        cin >> grid[i];
    }

    visited.assign(n, vector<int>(n, 0));
    color.assign(n, vector<int>(n, -1));
    sizee.clear();

    int col = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                cnt = 0;
                dfs(i, j, col);
                sizee[col] = cnt;
                col++;
            }
        }
    }

    build();

    int N = A.size(), M = a.size();
    for(int i=0;i<N;i++){

    }

}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}
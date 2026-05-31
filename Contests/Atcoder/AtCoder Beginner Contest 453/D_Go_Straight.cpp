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

#define pp pair<int,int>

// 0=Down, 1=Right, 2=Up, 3=Left
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char dir_char[4] = {'D', 'R', 'U', 'L'};

// row, column, and the direction we used to enter it
struct State {
    int r, c, d;
};

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m, '.'));
    pp st, en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S') st = {i, j};
            else if(grid[i][j] == 'G') en = {i, j};
        }
    }

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    vector<vector<vector<State>>> parent(n, vector<vector<State>>(m, vector<State>(4, {-1, -1, -1})));
    vector<vector<vector<char>>> move_char(n, vector<vector<char>>(m, vector<char>(4, ' ')));

    queue<State> qu;
    
    for(int d=0; d<4; d++){
        int nx = st.first + dir[d][0];
        int ny = st.second + dir[d][1];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#'){
            visited[nx][ny][d] = true;
            parent[nx][ny][d] = {st.first, st.second, -1};
            move_char[nx][ny][d] = dir_char[d];
            qu.push({nx, ny, d});
        }
    }

    State final_state = {-1, -1, -1};
    bool found = false;

    while(qu.size()){
        State curr = qu.front();
        qu.pop();

        if(curr.r == en.first && curr.c == en.second){
            final_state = curr;
            found = true;
            break;
        }

        char ch = grid[curr.r][curr.c];

        for(int d=0;d<4;d++){

            if(ch == 'o' && d != curr.d) continue;
            if(ch == 'x' && d == curr.d) continue;

            int nx = curr.r + dir[d][0];
            int ny = curr.c + dir[d][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#'){
                if(!visited[nx][ny][d]){
                    visited[nx][ny][d] = true;
                    parent[nx][ny][d] = curr;
                    move_char[nx][ny][d] = dir_char[d];
                    qu.push({nx, ny, d});
                }
            }
        }
    }

    if(!found){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        string path = "";
        State curr = final_state;
        
        while(curr.d != -1){
            path += move_char[curr.r][curr.c][curr.d];
            curr = parent[curr.r][curr.c][curr.d];
        }
        
        reverse(path.begin(), path.end());
        cout << path;
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
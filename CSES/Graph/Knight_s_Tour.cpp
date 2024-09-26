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

vector<vector<int>> grid;
int dir[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{1,-2},{2,-1}};
bool flag;

int degree(int x,int y){
    int cnt = 0;
    for(int d=0;d<8;d++){
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if(nx>=0 && nx<8 && ny>=0 && ny<8 && grid[nx][ny]==0){
            cnt++;
        }
    }
    return cnt;
}

bool f(int cx,int cy,int step){
    grid[cx][cy] = step;
    if(step==64){
        for(auto &x : grid){
            for(auto &y : x){
                cout << y << " ";
            }
            cout << endl;
        }
        return true;
    }
    
    vector<vector<int>> arr;
    for(int d=0;d<8;d++){
        int nx = cx + dir[d][0];
        int ny = cy + dir[d][1];
        if(nx>=0 && nx<8 && ny>=0 && ny<8 && grid[nx][ny]==0){
            int d = degree(nx,ny);
            arr.push_back({d,nx,ny});
        }
    }

    sort(arr.begin(),arr.end());

    for(auto &i : arr){
        if(f(i[1],i[2],step+1)){
            return true;
        }
    }

    grid[cx][cy] = 0;
    return false;
}

void solve(){
    int x,y;
    cin >> x >> y;

    swap(x,y);

    grid.assign(8,vector<int>(8,0));

    flag = true;
   
    f(x-1,y-1,1);
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
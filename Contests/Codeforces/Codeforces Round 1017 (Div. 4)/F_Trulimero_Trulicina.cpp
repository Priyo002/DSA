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
    int n, m, k;
    cin >> n >> m >> k;

    int cnt = (n*m)/k;

    map<int,int> e, o;
    for(int i=1;i<=k;i++){
        if(i&1) o[i] = cnt;
        else e[i] = cnt;
    }

    vector<pair<int,int>> even(e.begin(),e.end()), odd(o.begin(),o.end());

    vector<vector<int>> arr(n,vector<int>(m));

    int oIdx = 0, eIdx = 0;
    bool flag = true;

    if((n*m)&1){
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(flag){
                    arr[i][j] = odd[oIdx].first;
                    oIdx++;
                    oIdx %= (int)(o.size());
                    flag = false;
                }
                else{
                    arr[i][j] = even[eIdx].first;
                    eIdx++;
                    eIdx %= (int)(e.size());
                    flag = true;
                }
            }
        }
    }
    else{
        if(n%2 == 0){
            for(int j=0;j<m;j++){
                for(int i=0;i<n;i++){
                    if(flag){
                        arr[i][j] = odd[oIdx].first;
                        oIdx++;
                        oIdx %= (int)(o.size());
                        flag = false;
                    }
                    else{
                        arr[i][j] = even[eIdx].first;
                        eIdx++;
                        eIdx %= (int)(e.size());
                        flag = true;
                    }
                }
                flag = !flag;
            }
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(flag){
                        arr[i][j] = odd[oIdx].first;
                        oIdx++;
                        oIdx %= (int)(o.size());
                        flag = false;
                    }
                    else{
                        arr[i][j] = even[eIdx].first;
                        eIdx++;
                        eIdx %= (int)(e.size());
                        flag = true;
                    }
                }
                flag = !flag;
            }
        }
    }

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    flag = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
            // for(int d = 0;d<4;d++){
            //     int nx = i + dir[d][0], ny = j + dir[d][1];
            //     if(nx>=0 && ny>=0 && nx<n && ny<m && arr[i][j] == arr[nx][ny]){
            //         flag = false;
            //     }
            // }
        }
        cout << endl;
    }

    // if(flag)
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
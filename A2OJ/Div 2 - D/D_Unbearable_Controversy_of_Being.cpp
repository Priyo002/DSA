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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> isEdge(n+1,vector<int>(n+1,0)), graph(n+1,vector<int>());
    vector<int> nodePresent(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        nodePresent[a] = nodePresent[b] = 1;
        isEdge[a][b] = 1;
    }

    int ans = 0;
    for(int a=1;a<=n;a++){
        for(int c=1;c<=n;c++){
            if(a!=c){
                int cnt = 0;
                for(int idx=0;idx<graph[a].size();idx++){
                    int mid = graph[a][idx];
                    if(isEdge[a][mid] && isEdge[mid][c]){
                        cnt++;
                    }
                }
                ans += (cnt*(cnt - 1))/2;
            }
        }
    }

    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();


    return 0;
}
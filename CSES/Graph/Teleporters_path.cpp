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

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    vector<int> outdeg(n + 1, 0);

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indeg[y]++;
        outdeg[x]++;
    }

    for (int i = 2; i < n; i++){
        if (indeg[i] != outdeg[i]){
            cout << "IMPOSSIBLE";
            return;
        }
    }

    if (((outdeg[1] - indeg[1]) != 1) || ((outdeg[n] - indeg[n]) != -1)){
        cout << "IMPOSSIBLE";
        return;
    }

    stack<int> st;
    st.push(1);
    vector<int> path;

    while (st.size() > 0){
        int z = st.top();
        if ((indeg[z] == 0) && (outdeg[z] == 0)){
            path.push_back(z);
            st.pop();
        }
        else{
            int m = adj[z].size();
            st.push(adj[z][m - 1]);
            adj[z].pop_back();
            outdeg[z]--;
            indeg[adj[z][m - 1]]--;
        }
    }

    if ((int)path.size() != (m + 1)){
        cout << "IMPOSSIBLE";
        return;
    }

    reverse(path.begin(), path.end());
    for (auto &i : path){
        cout << i << " ";
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
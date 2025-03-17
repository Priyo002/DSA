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

    vector<set<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }

    for (int i = 1; i <= n; i++){
        if (deg[i] % 2){
            cout << "IMPOSSIBLE";
            return;
        }
    }

    stack<int> st;
    vector<int> path;
    st.push(1);

    while (st.size() > 0){
        int x = st.top();
        if (deg[x] == 0){
            st.pop();
            path.push_back(x);
        }
        else{
            int z = *(adj[x].begin());
            adj[x].erase(z);
            adj[z].erase(x);
            deg[x]--;
            deg[z]--;
            st.push(z);
        }
    }

    if (path.size() != (m + 1)){
        cout << "IMPOSSIBLE";
        return;
    }

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
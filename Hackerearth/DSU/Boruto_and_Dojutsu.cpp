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

vector<int> parent, rankk;
vector<set<int>> color;
vector<vector<int>> edges;

int findParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void merge(int x,int y){
    int parX = findParent(x);
    int parY = findParent(y);

    if(parX == parY) return;

    if(rankk[parX] < rankk[parY]) swap(parX,parY);

    rankk[parX] += rankk[parY];
    parent[parY] = parX;
    for(auto &c : color[parY]){
        color[parX].insert(c);
    }
    color[parY].clear();
}

void solve(){
    int n,m,q;
    cin >> n >> m >> q;

    rankk.assign(n+1,1);
    parent.resize(n+1);
    color.assign(n+1,set<int>());
    edges.clear();

    for(int i=1;i<=n;i++){
        int c;
        cin >> c;
        color[i].insert(c);
        parent[i] = i;
    }


    set<int> st;
    edges.push_back({-1,-1});
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
        st.insert(i);
    }


    vector<vector<int>> queries(q);
    
    for(int i=0;i<q;i++){
        int ch, x;
        cin >> ch >> x;
        queries[i] = {ch,x};
        if(ch == 1 && st.count(x)) st.erase(x);
    }   

    for(auto &idx : st){
        merge(edges[idx][0],edges[idx][1]);
    }

    vector<int> ans;
    for(int i=q-1;i>=0;i--){
        int ch = queries[i][0];
        if(ch == 1){
            int idx = queries[i][1];
            merge(edges[idx][0],edges[idx][1]);
        }
        else{
            int parX = findParent(queries[i][1]);
            ans.push_back(color[parX].size());
        }
    }

    for(int i=(int)ans.size()-1;i>=0;i--){
        cout << ans[i] << endl;
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
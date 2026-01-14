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

struct Union_Find{
    int sz,cc;
    vector<int> par,rank;
    void init(int n){
        sz = n;
        cc = n;
        par.clear();
        rank.clear();
        par.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=sz;i++){
            par[i] = i;
        }
    }
    int findParent(int x){
        if(x==par[x]) return x;
        else return par[x] = findParent(par[x]);
    }
    void addEdge(int x,int y){
        int parX = findParent(x);
        int parY = findParent(y);
        if(parX==parY) return;
        if(rank[parX]>=rank[parY]){
            rank[parX] += rank[parY];
            par[parY] = parX;
        }
        else{
            rank[parY] += rank[parX];
            par[parX] = parY;
        }
        cc--;
    }
    int getCC(){
        return cc;
    }
    void reset(){
        cc = sz;
        for(int i=0;i<=sz;i++){
            par[i] = i;
            rank[i] = 1;
        }
    }
    void print(){
        for(int i=0;i<=sz;i++){
            cout << i << "-> " << par[i] << " ";
        }
    }
};

int getDist(pair<int,int>& a, pair<int,int>& b){
    int x = a.first - b.first;
    int y = a.second - b.second;
    return x*x + y*y;
}

void solve(){
    int n;
    cin >> n;

    vector<pair<int,int>> points(n);
    vector<vector<int>> edges;

    for(int i=0;i<n;i++){
        cin >> points[i].first >> points[i].second;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dist = getDist(points[i], points[j]);
            edges.push_back({dist, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    Union_Find dsu;
    dsu.init(n);

    int ans = 0;
    for(auto &edge : edges){
        int wt = edge[0], u = edge[1], v = edge[2];
        if(dsu.findParent(u) != dsu.findParent(v)){
            ans += wt;
            dsu.addEdge(u, v);
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
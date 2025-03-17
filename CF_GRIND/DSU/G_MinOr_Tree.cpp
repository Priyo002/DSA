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

void solve(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    int ans = 0;
    int allOnes = -1; // 1111111..1 (In binary)
    for(int bit=32;bit>=0;bit--){

        Union_Find uf;
        uf.init(n);

        for(auto &x : edges){
            int u = x[0], v = x[1], w = x[2];
            int prefix = (w&(allOnes<<bit));
            int orr = (prefix|ans);
            if(orr == ans){
                if(uf.findParent(u)!=uf.findParent(v)){
                    uf.addEdge(u,v);
                }
            }
        }
        
        if(uf.getCC() != 1) ans |= (1LL<<bit);
    }

    cout << ans << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
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
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

struct Union_Find{
    int sz,cc,mxGroupSz;
    vector<int> par,rank;
    void init(int n){
        sz = n;
        cc = n;
        mxGroupSz = 1;
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
            mxGroupSz = max(mxGroupSz,rank[parX]);
            par[parY] = parX;
        }
        else{
            rank[parY] += rank[parX];
            mxGroupSz = max(mxGroupSz,rank[parY]);
            par[parX] = parY;
        }
        cc--;
    }
    int getCC(){
        return cc;
    }
    int getMxGroupSize(){
        return mxGroupSz;
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

    Union_Find dsu;
    dsu.init(n);

    while(m--){
        int u,v;
        cin >> u >> v;
        dsu.addEdge(u,v);

        cout << dsu.getCC() << " " << dsu.getMxGroupSize() << endl;
    }
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
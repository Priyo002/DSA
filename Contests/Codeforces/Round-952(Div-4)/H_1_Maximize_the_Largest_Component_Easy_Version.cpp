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
    int sz,cc;
    vector<int> par,rank,t1,t2;
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

    void startt(){
        t1 = par;
        t2 = rank;
    }
    void endd(){
        par = t1,
        rank = t2;
    }
    int getSize(int x){
        return rank[x];
    }

    void print(){
        for(int i=0;i<=sz;i++){
            cout << i << "-> " << par[i] << " " << rank[i] << endl;
        }
    }
};

void solve(){
    int n,m;
    cin >> n >> m;

    vector<string> graph;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        graph.push_back(s);
    }

    Union_Find a;
    a.init((n*m));
    
    int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]=='.') continue;
            for(int d=0;d<4;d++){
                int nx = i+dir[d][0];
                int ny = j+dir[d][1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && graph[nx][ny]=='#'){
                    a.addEdge(i*m+j,nx*m+ny);
                }
            }
        }
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        set<int> st;
        int cnt = 0;
        for(int j=0;j<m;j++){
            if(graph[i][j]=='#'){
                st.insert(a.findParent(i*m+j));
            }
            else{
                cnt++;
                if(i+1<n && graph[i+1][j]=='#') st.insert(a.findParent((i+1)*m+j));
                if(i-1>=0 && graph[i-1][j]=='#') st.insert(a.findParent((i-1)*m+j));
            }
        }
        for(auto x : st){
            cnt += a.getSize(x);
        }
        ans = max(ans,cnt);
    }
    for(int j=0;j<m;j++){
        set<int> st;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(graph[i][j]=='#'){
                st.insert(a.findParent(i*m+j));
            }
            else{
                cnt++;
                if(j+1<m && graph[i][j+1]=='#') st.insert(a.findParent(i*m+(j+1)));
                if(j-1>=0 && graph[i][j-1]=='#') st.insert(a.findParent(i*m+(j-1)));
            }
        }
        for(auto x : st){
            cnt += a.getSize(x);
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
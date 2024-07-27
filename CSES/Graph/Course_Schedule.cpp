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
int n,m;
vector<list<int>> graph;
vector<int> inDegree;

vector<int> getTopo(){
    
    queue<int> qu;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            qu.push(i);
        }
    }   
    vector<int> topo;
    while(qu.size()){
        auto curr = qu.front();
        qu.pop();

        topo.push_back(curr);
        for(auto neigh : graph[curr]){
            inDegree[neigh]--;
            if(inDegree[neigh]==0){
                qu.push(neigh);
            }
        }
    }  

    return topo; 
}

void solve(){
    
    cin >> n >> m;

    graph.clear();
    graph.resize(n+1,list<int>());
    inDegree.clear();
    inDegree.resize(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    vector<int> topo = getTopo();

    if(topo.size()!=n){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(auto x : topo) cout << x << " ";

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
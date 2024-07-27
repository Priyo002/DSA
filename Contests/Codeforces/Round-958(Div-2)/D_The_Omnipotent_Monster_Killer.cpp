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

int n;
vector<int> arr,visited,dep;
vector<list<int>> graph;

void dfs(int src,int h){
    dep[src] = h;
    visited[src] = 1;
    for(auto neigh : graph[src]){
        if(!visited[neigh]){
            dfs(neigh,h+1);
        }
    }
}

void solve(){

    cin >> n;

    graph.clear();
    graph.resize(n+1,list<int>());

    arr.clear();
    arr.resize(n+1);

    visited.clear();
    visited.resize(n+1,0);

    dep.clear();
    dep.resize(n+1,0);

    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1;i<=n-1;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0;

    
    for(int i=1;i<=n;i++){
        dfs(1,1);
        int sum1 = 0, sum2 = 0;
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(dep[i]&1) sum1 += arr[i];
            else sum2 += arr[i];
            sum += arr[i];
        }
        ans = max(ans,sum+(sum-max(sum1,sum2)));
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
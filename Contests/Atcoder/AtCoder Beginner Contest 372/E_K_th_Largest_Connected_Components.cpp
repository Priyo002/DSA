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

vector<int> parent,rankk;
vector<vector<int>> arr;

int getParent(int x){
    if(x==parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void merge(int u,int v){
    vector<int> a = arr[u];
    vector<int> b = arr[v];

    vector<int> temp;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    while(i<n && j<m){
        if(a[i]>=b[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(b[j]);
            j++;
        }
    }

    while(i<n){
        temp.push_back(a[i]);
        i++;
    }

    while(j<m){
        temp.push_back(b[j]);
        j++;
    }

    while(temp.size()>=11){
        temp.pop_back();
    }

    arr[u] = temp;
}

void addEdge(int u,int v){
    u = getParent(u);
    v = getParent(v);
    if(u==v) return;
    if(rankk[u]>=rankk[v]){
        merge(u,v);
        rankk[u] += rankk[v];
        parent[v] = u;
    }
    else{
        merge(v,u);
        rankk[v] += rankk[u];
        parent[u] = v;
    }
}

int getQuery(int u,int k){
    u = getParent(u);
    if(arr[u].size()<k) return -1;
    return arr[u][k-1];
}

void solve(){
    int n,q;
    cin >> n >> q;

    parent.assign(n+1,0);
    rankk.assign(n+1,1);

    for(int i=1;i<=n;i++) parent[i] = i;

    arr.clear();
    arr.resize(n+1,vector<int>());

    for(int i=1;i<=n;i++){
        arr[i].push_back(i);
    }

    while(q--){
        int ch;
        cin >> ch;
        if(ch==1){
            int u,v;
            cin >> u >> v;
            addEdge(u,v);
        }
        else{
            int v,k;
            cin >> v >> k;

            cout << getQuery(v,k) << endl;
        }
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
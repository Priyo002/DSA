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
 
vector<int> rankk, parent;

int findParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}
 
int merge(int a,int b){
    int parA = findParent(a);
    int parB = findParent(b);
 
    if(parA == parB) return 0;
 
    if(rankk[parA] < rankk[parB]) swap(parA,parB);
 
    rankk[parA] += rankk[parB];
    parent[parB] = parA;
    return 1;
}
 
int f(string &s){
    int i = 0, j = (int)s.size() - 1;
    int cost = 0;
    while(i<j){
        int x = findParent(s[i]-'a');
        int y = findParent(s[j]-'a');
        if(x!=y) cost++;
        i++, j--;
    }
    return cost;
}
 
void solve(){
    int n;
    cin >> n;
 
    string s;
    cin >> s;
 
    rankk.assign(26,1);
    parent.resize(26);
    for(int i=0;i<26;i++){
        parent[i] = i;
    }
 
    int q;
    cin >> q;
 
    int lastCost = f(s);
 
    while(q--){
        int ch;
        cin >> ch;
 
        if(ch == 1){
            char a,b;
            cin >> a >> b;
            
            int flag = merge(a-'a', b-'a');
            if(flag){
                lastCost = f(s);
            }
        }
        else{
            cout << lastCost << endl;
        }
 
    }
}
 
int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();
 
 
    return 0;
}
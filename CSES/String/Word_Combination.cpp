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

struct Node{
    vector<int> child;
    bool terminal;
    Node(){
        terminal = false;
        child.assign(26,-1);
    }
};


vector<Node> arr;

void insert(string &s){
    int currNodeIdx = 0;
    for(auto &ch : s){
        if(arr[currNodeIdx].child[ch-'a'] == -1){
            Node newNode;
            arr.push_back(newNode);
            arr[currNodeIdx].child[ch-'a'] = arr.size() - 1;
        }
        currNodeIdx = arr[currNodeIdx].child[ch-'a'];
    }
    arr[currNodeIdx].terminal = true;
}


void solve(){
    string s;
    cin >> s;

    int n = s.size();

    int m;
    cin >> m;

    arr.clear();
    Node root;
    arr.push_back(root);

    for(int i=0;i<m;i++){
        string str;
        cin >> str;
        insert(str);
    }

    vector<int> dp(n+1,0);
    dp[n] = 1;
    for(int i=n-1;i>=0;i--){
        int cnt = 0, currNodeIdx = 0;
        for(int j=i;j<n;j++){
            if(arr[currNodeIdx].child[s[j]-'a'] == -1) break;

            currNodeIdx = arr[currNodeIdx].child[s[j]-'a'];
            if(arr[currNodeIdx].terminal){
                cnt += dp[j+1];
                cnt %= mod;
            }
            
        }
        dp[i] = cnt;
    }
    cout << dp[0] << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
   // cin >> _t;
    while(_t--)
        solve();


    return 0;
}
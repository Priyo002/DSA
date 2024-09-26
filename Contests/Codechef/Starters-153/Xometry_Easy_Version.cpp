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
    bool terminal;
    int cnt;
    vector<Node*> arr;
    Node(){
        terminal = false;
        arr.assign(2,NULL);
        cnt = 0;
    }
};

struct Trie{
    Node* root,*root2;
    map<int,int> mp;
    int ans;
    Trie(){
        root = new Node();
        root2 = new Node();
        mp.clear();
        ans = 0;
    }

    void insert(int num){
        Node* curr = root;
        for(int i=0;i<=20;i++){
            int bit = ((num>>i)&1);
            if(curr->arr[bit]==NULL){
                curr->arr[bit] = new Node();
            }
            curr = curr->arr[bit];
        }
        curr->terminal = true;
        curr->cnt++;
    }

    void dfs(Node* curr,int currVal,int bit){
        if(curr->terminal==true){
            mp[currVal]++;
        }
        if(curr->arr[0]!=NULL){
            dfs(curr->arr[0],currVal,bit+1);
        }
        if(curr->arr[1]!=NULL){
            dfs(curr->arr[1],(currVal^(1LL<<bit)),bit+1);
        }
    }

    void query(int val){
        Node* curr = root;
        dfs(curr,val,0);
    }

    void insert2(int num){
        Node* curr = root2;
        for(int i=0;i<=20;i++){
            int bit = ((num>>i)&1);
            if(curr->arr[bit]==NULL){
                curr->arr[bit] = new Node();
            }
            curr = curr->arr[bit];
        }
        curr->terminal = true;
        curr->cnt++;
    }

    void dfs2(Node* curr,int currVal,int bit){
        if(curr->terminal==true){
            ans += mp[currVal]-1;
        }
        if(curr->arr[0]!=NULL){
            dfs2(curr->arr[0],currVal,bit+1);
        }
        if(curr->arr[1]!=NULL){
            dfs2(curr->arr[1],(currVal^(1LL<<bit)),bit+1);
        }
    }

    void query2(int num){
        Node* curr = root2;
        dfs2(curr,num,0);
    }

    int f(){
        return ans;
    }
};

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    Trie t;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        //t.insert(arr[i]);
    }

    for(int i=n-1;i>=0;i--){
        t.query(arr[i]);
        t.insert(arr[i]);
    }

    for(int i=n-1;i>=0;i--){
        t.query2(arr[i]);
        t.insert2(arr[i]);
    }

    cout << 4*t.f() << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
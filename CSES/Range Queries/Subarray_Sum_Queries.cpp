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
    int totalSum;
    int leftSum;
    int rightSum;
    int maxSum;
    Node(int x = 0){
        totalSum = x;
        leftSum = rightSum = maxSum = max(0LL,x);
    }
};

vector<Node> seg;
vector<int> arr;

Node merge(Node &a,Node &b){
    Node ans;
    ans.totalSum = a.totalSum + b.totalSum;
    ans.leftSum = max({a.leftSum,a.totalSum+b.leftSum});
    ans.rightSum = max({b.rightSum,b.totalSum+a.rightSum});
    ans.maxSum = max({a.maxSum,b.maxSum,a.rightSum+b.leftSum,ans.totalSum});
    return ans;
}

void build(int idx,int l,int r){
    if(l==r){
        seg[idx] = Node(arr[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    seg[idx] = merge(seg[2*idx],seg[2*idx+1]);
}

void update(int idx,int l,int r,int pos,int val){
    if(pos>r || pos<l) return;
    if(l==r){
        seg[idx] = Node(val);
        return;
    }
    int mid = (l+r)/2;
    update(2*idx,l,mid,pos,val);
    update(2*idx+1,mid+1,r,pos,val);
    seg[idx] = merge(seg[2*idx],seg[2*idx+1]);
}



void solve(){
    int n,q;
    cin >> n >> q;

    arr.assign(n,0);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    seg.resize(4*n);

    build(1,0,n-1);

    while(q--){
        int pos,val;
        cin >> pos >> val;
        pos--;
        update(1,0,n-1,pos,val);
        cout << seg[1].maxSum << endl;
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
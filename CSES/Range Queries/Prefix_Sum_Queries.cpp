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
    int lazy;
    int mx;
    Node(int x=0){
        lazy = 0;
        mx = x;
    }
};

vector<int> arr,pref;
vector<Node> seg;

void push(int idx,int l,int r){
    if(seg[idx].lazy){
        seg[idx].mx += seg[idx].lazy;
        if(l!=r){
            seg[2*idx].lazy += seg[idx].lazy;
            seg[2*idx+1].lazy += seg[idx].lazy;
        }
    }
    seg[idx].lazy = 0;
}

Node merge(Node a,Node b){
    Node ans;
    ans.mx = max(a.mx,b.mx);
    return ans;
}

void build(int idx,int l,int r){
    if(l==r){
        seg[idx] = Node(pref[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r); 
    seg[idx] = merge(seg[2*idx],seg[2*idx+1]);
}

void update(int idx,int l,int r,int lq,int rq,int val){
    push(idx,l,r);
    if(l>rq || r<lq) return;
    if(l>=lq && r<=rq){
        seg[idx].lazy += val;
        push(idx,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(2*idx,l,mid,lq,rq,val);
    update(2*idx+1,mid+1,r,lq,rq,val);
    seg[idx] = merge(seg[2*idx],seg[2*idx+1]);
}

int query(int idx,int l,int r,int lq,int rq){
    push(idx,l,r);
    if(l>rq || r<lq) return -INF;
    if(l>=lq && r<=rq){
        return seg[idx].mx;
    }
    int mid = (l+r)/2;
    return max(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq));
}

int getSum(int idx,int l,int r,int pos){
    push(idx,l,r);
    if(l==r){
        return seg[idx].mx;
    }
    int mid = (l+r)/2;
    if(pos<=mid){
        return getSum(2*idx,l,mid,pos);
    }
    else{
        return getSum(2*idx+1,mid+1,r,pos);
    }
}

void solve(){
    int n,q;
    cin >> n >> q;

    arr.resize(n);
    pref.resize(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
        pref[i] = arr[i];
        if(i) pref[i] += pref[i-1];
    }

    seg.resize(4*n);

    build(1,0,n-1);

    while(q--){
        int ch;
        cin >> ch;
        if(ch==1){
            int pos,val;
            cin >> pos >> val;
            pos--;
            update(1,0,n-1,pos,n-1,-arr[pos]);
            arr[pos] = val;
            update(1,0,n-1,pos,n-1,arr[pos]);
        }
        else{
            int lq,rq;
            cin >> lq >> rq;
            lq--,rq--;
            int ans = query(1,0,n-1,lq,rq);
            if(lq) ans -= getSum(1,0,n-1,lq-1);
            cout << max(0LL,ans) << endl;
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
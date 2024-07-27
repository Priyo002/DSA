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

using ap = pair<int,int>;
#define MP make_pair

struct node{
    int sum;
    ap lazy;//{a,d}
    node(){
        sum = 0;
        lazy = MP(0,0);
    }
};


int arr[200100];
node seg[800800];

node merge(node a,node b){
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

void build(int idx,int l,int r){
    if(l==r){
        seg[idx].sum = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    seg[idx] = merge(seg[2*idx],seg[2*idx+1]);
}

inline int getnth(ap curr,int n){
    return curr.first+(n-1)*curr.second;
}

inline int getSum(ap curr,int n){
    return n*(2*curr.first+(n-1)*curr.second)/2;
}

void push_down(ap curr,int idx){
    seg[idx].lazy.first += curr.first;
    seg[idx].lazy.second += curr.second;
}

void push(int idx,int l,int r){
    if(seg[idx].lazy.first==0 && seg[idx].lazy.second==0) return;
   
    if(l!=r){
        push_down(seg[idx].lazy,2*idx);
        int mid = (l+r)/2;
        int nth = (mid+1)-(l-1);
        int newa = getnth(seg[idx].lazy,nth);
        push_down(MP(newa,seg[idx].lazy.second),2*idx+1);
    }

    seg[idx].sum += getSum(seg[idx].lazy,r-l+1);
    seg[idx].lazy = MP(0,0);

}

void update(int idx,int l,int r,int lq,int rq,int d){
    push(idx,l,r);   
    if(lq>r || rq<l) return;
    if(l>=lq && r<=rq){
        seg[idx].lazy = MP(l-lq+1,d);
        push(idx,l,r);
        return;
    } 
    int mid = (l+r)/2;

    update(2*idx,l,mid,lq,rq,d);
    update(2*idx+1,mid+1,r,lq,rq,d);

    seg[idx] = merge(seg[2*idx],seg[2*idx+1]);
}

int query(int idx,int l,int r,int lq,int rq){
    push(idx,l,r);
    if(lq>r || rq<l) return 0;
    if(l>=lq && r<=rq){
        return seg[idx].sum;
    }
    int mid = (l+r)/2;
    return query(2*idx,l,mid,lq,rq) + query(2*idx+1,mid+1,r,lq,rq);
}

void solve(){
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> arr[i];

    build(1,1,n);

    while(q--){
        int ch,a,b;
        cin >> ch >> a >> b;
        if(ch==1){
            update(1,1,n,a,b,1);
        }
        else{
            cout << query(1,1,n,a,b) << endl;
        }
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
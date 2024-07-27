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

struct node{
    int sum,lazySet,lazyAdd;
    node(){
        sum = lazyAdd = lazySet = 0;
    }
};

int arr[200100];
node seg[800800];

node merge(node a,node b){
    node temp;
    temp.sum = a.sum + b.sum;
    return temp;
}

void pushDown(int parIdx,int childIdx){
    if(seg[parIdx].lazyAdd!=0){
        if(seg[childIdx].lazyAdd!=0){
            seg[childIdx].lazyAdd += seg[parIdx].lazyAdd;
        }
        else if(seg[childIdx].lazySet!=0){
            seg[childIdx].lazySet += seg[parIdx].lazyAdd;
        }
        else{
            seg[childIdx].lazyAdd += seg[parIdx].lazyAdd;
        }
    }
    else if(seg[parIdx].lazySet!=0){
        seg[childIdx].lazySet = seg[parIdx].lazySet;
        seg[childIdx].lazyAdd = 0;
    }
}

void push(int idx,int l,int r){
    if(seg[idx].lazyAdd!=0){
        seg[idx].sum += seg[idx].lazyAdd*(r-l+1);
        if(l!=r){
            pushDown(idx,2*idx);
            pushDown(idx,2*idx+1);
        }
        seg[idx].lazyAdd = 0;
    }
    else if(seg[idx].lazySet!=0){
        seg[idx].sum = seg[idx].lazySet*(r-l+1);
        if(l!=r){
            pushDown(idx,2*idx);
            pushDown(idx,2*idx+1);
        }
        seg[idx].lazySet = 0;
    }   
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

void update(int idx,int l,int r,int lq,int rq,int val,int ch){
    push(idx,l,r);
    if(lq>r || rq<l) return;
    if(l>=lq && r<=rq){
        if(ch==1) seg[idx].lazyAdd += val;
        else if(ch==2) seg[idx].lazySet = val;
        push(idx,l,r);
        return;
    }

    int mid = (l+r)/2;
    update(2*idx,l,mid,lq,rq,val,ch);
    update(2*idx+1,mid+1,r,lq,rq,val,ch);

    seg[idx] = merge(seg[2*idx],seg[2*idx+1]);
}


int query(int idx,int l,int r,int lq,int rq){
    push(idx,l,r);
    if(rq<l || lq>r) return 0LL;
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
        int ch;
        cin >> ch;
        if(ch==1){
            int lq,rq,val;
            cin >> lq >> rq >> val;
            update(1,1,n,lq,rq,val,ch);
        }
        else if(ch==2){
            int lq,rq,val;
            cin >> lq >> rq >> val;
            update(1,1,n,lq,rq,val,ch);
        }
        else{
            int lq,rq;
            cin >> lq >> rq;
            cout << query(1,1,n,lq,rq) << endl;
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
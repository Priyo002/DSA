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

int arr[200100];
int seg[800800];

void build(int idx,int l,int r){
    if(l==r){
        seg[idx] = arr[l];//store max element index
        return;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);

    seg[idx] = max(seg[2*idx],seg[2*idx+1]);
}

void update(int idx,int l,int r,int pos,int val){
    if(pos<l || pos>r) return;
    if(l==r){
        seg[idx] -= val;
        return;
    }
    int mid = (l+r)/2;
    update(2*idx,l,mid,pos,val);
    update(2*idx+1,mid+1,r,pos,val);

    seg[idx] = max(seg[2*idx],seg[2*idx+1]);
}

int query(int idx,int l,int r,int val){
    if(seg[idx]<val) return 0;
    if(l==r){
        return l;
    }
    int mid = (l+r)/2;
    if(seg[2*idx]>=val){
        return query(2*idx,l,mid,val);
    }
    else{
        return query(2*idx+1,mid+1,r,val);
    }
}


void solve(){
    int n,q;
    cin >> n >> q;

    for(int i=1;i<=n;i++) cin >> arr[i];

    build(1,1,n);

    while(q--){
        int val;
        cin >> val;
        int idx = query(1,1,n,val);
        cout << idx << " ";
        update(1,1,n,idx,val);
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
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

vector<int> seg, diff;

void build(int idx,int l,int r){
    if(l==r){
        seg[idx] = diff[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    seg[idx] = __gcd(seg[2*idx],seg[2*idx+1]);
}

int query(int idx,int l,int r,int lq,int rq){
    if(lq>r || rq<l) return 0;
    if(l>=lq && r<=rq) return seg[idx];
    int mid = l + (r-l)/2;
    return __gcd(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq));
}

void solve(){
    int n,q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    if(n==1){
        while(q--){
            int l,r;
            cin >> l >> r;
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }

    int m = n-1;
    diff.assign(m,0);
    for(int i=0;i<m;i++){
        diff[i] = abs(arr[i+1]-arr[i]);
    }

    seg.assign(4*m,0);
    build(1,0,m-1);

    while(q--){
        int l,r;
        cin >> l >> r;
        l--,r--;

        cout << query(1,0,m-1,l,r-1) << " ";
    }
    cout << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
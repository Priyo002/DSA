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
int seg[800400];

void build(int idx,int l,int r){
    if(l==r){
        seg[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);

    seg[idx] = min(seg[2*idx],seg[2*idx+1]);
}

void update(int idx,int l,int r,int pos,int val){
    if(pos<l || pos>r) return;
    if(l==r){
        arr[l] = val;
        seg[idx] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*idx,l,mid,pos,val);
    update(2*idx+1,mid+1,r,pos,val);

    seg[idx] = min(seg[2*idx],seg[2*idx+1]);
}

int query(int idx,int l,int r,int lq,int rq){
    if(r<lq || l>rq) return 1e18;
    
    if(l>=lq && r<=rq){
        return seg[idx];
    }

    int mid = (l+r)/2;

    return min(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq));
}

void solve(){

    int n,q;
    cin >> n >> q;

    for(int i=0;i<n;i++) cin >> arr[i];

    build(1,0,n-1);

    while(q--){
        int ch;
        cin >> ch;
        if(ch==1){
            int pos,val;
            cin >> pos >> val;
            pos--;
            update(1,0,n-1,pos,val);
        }
        else{
            int lq,rq;
            cin >> lq >> rq;

            lq--,rq--;

            cout << query(1,0,n-1,lq,rq) << endl;
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
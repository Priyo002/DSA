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

int n,q;
vector<int> arr,seg;

void build(int idx,int l,int r,int a,int b){
    if(l==r){
        if(arr[l]>=a && arr[l]<=b) seg[idx] = 1;
        else seg[idx] = 0;
        return;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid,a,b);
    build(2*idx+1,mid+1,r,a,b);

    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

void solve(){
    cin >> n >> q;

    arr.clear();
    seg.clear();

    arr.resize(n);
    seg.resize(4*n+1);

    for(int i=0;i<n;i++) cin >> arr[i];

    while(q--){
        char ch;
        int a,b;
        cin >> ch >> a >> b;

        if(ch=='!'){
            a--;
            arr[a] = b;
        }
        else{
            build(1,0,n-1,a,b);
            cout << seg[1] << endl;
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
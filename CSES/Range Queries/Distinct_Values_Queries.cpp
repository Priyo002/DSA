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

int n,q;
vector<int> prevIdx;
vector<vector<int>> seg;

void merge(int idx){
    int i = 0, j = 0;
    int m1 = seg[2*idx].size(), m2 = seg[2*idx + 1].size();
    while(i<m1 && j<m2){
        if(seg[2*idx][i]<=seg[2*idx+1][j]){
            seg[idx].push_back(seg[2*idx][i]);
            i++;
        }
        else{
            seg[idx].push_back(seg[2*idx+1][j]);
            j++;
        }
    }
    while(i<m1){
        seg[idx].push_back(seg[2*idx][i]);
        i++;
    }
    while(j<m2){
        seg[idx].push_back(seg[2*idx+1][j]);
        j++;
    }
}

void build(int idx,int l,int r){
    if(l==r){
        seg[idx].push_back(prevIdx[l]);
        return;
    }
    int mid = l+(r-l)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);

    merge(idx);
}

int query(int idx,int l,int r,int lq,int rq){
    if(lq>r || rq<l) return 0;
    if(l>=lq && r<=rq){
        int cnt = upper_bound(seg[idx].begin(),seg[idx].end(),lq-1) - seg[idx].begin();
        return cnt;
    }
    int mid = l+(r-l)/2;
    return query(2*idx,l,mid,lq,rq) + query(2*idx+1,mid+1,r,lq,rq);
}

void solve(){
    cin >> n >> q;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    prevIdx.assign(n,-1);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])!=mp.end()){
            prevIdx[i] = mp[arr[i]];
        }
        mp[arr[i]] = i;
    }   
    seg.assign(4*n,vector<int>());
    build(1,0,n-1);

    while(q--){
        int lq,rq;
        cin >> lq >> rq;
        lq--,rq--;

        cout << query(1,0,n-1,lq,rq) << endl;
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
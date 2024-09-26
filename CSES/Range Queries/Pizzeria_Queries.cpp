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

struct Left{

    vector<int> seg,arr;

    Left(vector<int>& arr){
        int n = arr.size();
        seg.assign(4*n+1,0);
        this->arr = arr;
        build(1,0,n-1);
    }

    void build(int idx,int l,int r){
        if(l==r){
            seg[idx] = arr[l]-l;
            return;
        }
        int mid = (l+r)/2;
        build(2*idx,l,mid);
        build(2*idx+1,mid+1,r);
        seg[idx] = min(seg[2*idx],seg[2*idx+1]);
    }

    void update(int idx,int l,int r,int pos,int val){
        if(pos>r || pos<l) return;
        if(l==r){
            seg[idx] = val-pos;
            return;
        }
        int mid = (l+r)/2;
        update(2*idx,l,mid,pos,val);
        update(2*idx+1,mid+1,r,pos,val);
        seg[idx] = min(seg[2*idx],seg[2*idx+1]);
    }
    
    int query(int idx,int l,int r,int lq,int rq){
        if(l>rq || r<lq) return INF;
        if(l>=lq && r<=rq){
            return seg[idx];
        }
        int mid = (l+r)/2;
        return min(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq));
    }

};

struct Right{

    vector<int> seg,arr;

    Right(vector<int>& arr){
        int n = arr.size();
        seg.assign(4*n+1,0);
        this->arr = arr;
        build(1,0,n-1);
    }

    void build(int idx,int l,int r){
        if(l==r){
            seg[idx] = arr[l]+l;
            return;
        }
        int mid = (l+r)/2;
        build(2*idx,l,mid);
        build(2*idx+1,mid+1,r);
        seg[idx] = min(seg[2*idx],seg[2*idx+1]);
    }

    void update(int idx,int l,int r,int pos,int val){
        if(pos>r || pos<l) return;
        if(l==r){
            seg[idx] = val+pos;
            return;
        }
        int mid = (l+r)/2;
        update(2*idx,l,mid,pos,val);
        update(2*idx+1,mid+1,r,pos,val);
        seg[idx] = min(seg[2*idx],seg[2*idx+1]);
    }
    
    int query(int idx,int l,int r,int lq,int rq){
        if(l>rq || r<lq) return INF;
        if(l>=lq && r<=rq){
            return seg[idx];
        }
        int mid = (l+r)/2;
        return min(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq));
    }

};


void solve(){
    
    int n,q;
    cin >> n >> q;

    vector<int> price(n);
    for(int i=0;i<n;i++){
        cin >> price[i];
    }

    Left l(price);
    Right r(price);

    while(q--){
        int ch;
        cin >> ch;
        if(ch==1){
            int pos,val;
            cin >> pos >> val;

            pos--;

            l.update(1,0,n-1,pos,val);
            r.update(1,0,n-1,pos,val);
        }
        else{
            int idx;
            cin >> idx;
            idx--;

            int ans = min(l.query(1,0,n-1,0,idx)+idx,r.query(1,0,n-1,idx,n-1)-idx);

            cout << ans << endl;
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
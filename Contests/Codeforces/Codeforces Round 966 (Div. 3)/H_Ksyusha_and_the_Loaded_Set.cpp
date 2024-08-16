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

vector<int> seg;

void update(int idx,int l,int r,int pos,int val){
    if(pos<l || pos>r) return;
    if(l==r){
        seg[idx] = val;
        return;
    }
    int mid = l + (r-l)/2;
    if(pos<=mid){
        update(2*idx,l,mid,pos,val);
    }
    else{
        update(2*idx+1,mid+1,r,pos,val);
    }
    seg[idx] = max(seg[2*idx],seg[2*idx+1]);
}

int query(int idx,int l,int r,int val){
    if(seg[idx]<val) return 0;
    if(l==r){
        return l;
    }
    int mid = l + (r-l)/2;
    if(seg[2*idx]>=val){
        return query(2*idx,l,mid,val);
    }
    else{
        return query(2*idx+1,mid+1,r,val);
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n+2);

    int mx = 2e6+5;

    seg.clear();
    seg.resize(4*mx,0);

    arr[0] = 0;
    arr[n+1] = INF;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    set<int> st;
    st.insert(0);

    for(int i=1;i<=n+1;i++){
        int diff = arr[i] - arr[i-1]-1;
        update(1,0,mx,arr[i-1]+1,diff);
        st.insert(arr[i]);
    }
    
    int q;
    cin >> q;

    while(q--){
        char ch;
        cin >> ch;
       
        if(ch=='?'){
            int k;
            cin >> k;
            cout << query(1,0,mx,k) << " ";
        }
        else if(ch=='+'){
            int x;
            cin >> x;

            auto it = st.upper_bound(x);
            int val = *it;
            update(1,0,mx,x+1,val-x-1);
            it--;
            val = *it;
            update(1,0,mx,val+1,x-val-1);

            st.insert(x);
        }
        else if(ch=='-'){
            int x;
            cin >> x;

            int val1 = *st.upper_bound(x);
            int val2 = *(--st.lower_bound(x));

            update(1,0,mx,val2+1,val1 - val2 - 1);
            update(1,0,mx,x+1,0);

            st.erase(x);
        }
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
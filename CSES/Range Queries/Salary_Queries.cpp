#include<bits/stdc++.h>
using namespace std;
using pp = pair<int,int>;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<pp, null_type,less<pp>, rb_tree_tag,tree_order_statistics_node_update>

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

void solve(){
    int n,q;
    cin >> n >> q;

    ordered_set st;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        int salary;
        cin >> salary;
        arr[i] = salary;
        st.insert({salary,i});
    }

    while(q--){
        char ch;
        cin >> ch;
        if(ch=='!'){
            int pos,val;
            cin >> pos >> val;
            pos--;
            auto it = st.find({arr[pos],pos});
            arr[pos] = val;
            st.erase(it);
            st.insert({val,pos});
        }
        else{
            int a,b;
            cin >> a >> b;

            int cnt1 = st.order_of_key({b+1,-1});
            int cnt2 = st.order_of_key({a,-1});

            cout << cnt1-cnt2 << endl;
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
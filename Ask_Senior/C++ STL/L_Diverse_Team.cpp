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



void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
   
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    unordered_set<int> st(arr.begin(),arr.end());

    if(st.size() < k) cout << "NO";
    else{
        cout << "YES" << endl;
        unordered_set<int> stt;
        for(int i=0;i<n;i++){
            if(!stt.count(arr[i])){
                k--;
                cout << i+1 << " ";
                stt.insert(arr[i]);
                if(k == 0) break;
            }
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
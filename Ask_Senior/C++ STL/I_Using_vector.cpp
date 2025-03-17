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
    int n,q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    while(q--){
        string query;
        cin >> query;
        if(query == "pop_back" && arr.size()){
            arr.pop_back();
        }  
        else if(query == "front" && arr.size()){
            cout << arr[0] << endl;
        }
        else if(query == "back" && arr.size()){
            cout << arr.back() << endl;
        }
        else if(query == "sort"){
            int lq,rq;
            cin >> lq >> rq;
            int l = min(lq,rq), r = max(lq,rq);
            l--, r--;
            if(r<arr.size())
                sort(arr.begin() + l, arr.begin() + r + 1);
        }
        else if(query == "reverse"){
            int lq,rq;
            cin >> lq >> rq;
            int l = min(lq,rq), r = max(lq,rq);
            l--, r--;
            if(r<arr.size())
                reverse(arr.begin() + l,arr.begin() + r + 1);
        }
        else if(query == "print"){
            int pos;
            cin >> pos;
            pos--;
            if(pos<arr.size())
                cout << arr[pos] << endl;
        }
        else if(query == "push_back"){
            int x;
            cin >> x;
            arr.push_back(x);
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
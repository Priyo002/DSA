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

vector<int> arr;

void solve(){
    int n, s;
    cin >> n >> s;

    arr.clear();
    arr.resize(n);

    int mini = INF;
    int total = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mini = min(mini,arr[i]);
        total += arr[i];
    }

    if(s < mini){
        cout << "No";
        return;
    }

    if(total == s){
        cout << "Yes";
        return;
    }

    s %= total;

    if(s == 0){
        cout << "Yes";
        return;
    }

    set<int> st;
    st.insert(0);

    arr.insert(arr.end(),arr.begin(),arr.end());

    int currSum = 0;
    for(int i=0;i<2*n;i++){
        currSum += arr[i];
        if(st.count(currSum - s)){
            cout << "Yes";
            return;
        }
        st.insert(currSum);
    }

    cout << "No" << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
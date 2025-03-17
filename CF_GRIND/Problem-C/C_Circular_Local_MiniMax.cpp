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
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.rbegin(),arr.rend());
    vector<int> ans(n);
    int j = 0;
    for(int i=0;i<n;i+=2){
        ans[i] = arr[j++];
    }
    //j = n-1;
    for(int i=1;i<n;i+=2){
        ans[i] = arr[j++];
    }
    bool f1 = true, f2 = true;
    for(int i=0;i<n;i++){
        int prev, next;
        if(i%2==0){
            if(i==0) prev = ans[n-1];
            else prev = ans[i-1];
            if(i==n-1) next = ans[0];
            else next = ans[i+1];

            if(ans[i]<=prev || ans[i]<=next){
                f1 = false;
                break;
            }
        }
        else{
            if(i==0) prev = ans[n-1];
            else prev = ans[i-1];
            if(i==n-1) next = ans[0];
            else next = ans[i+1];

            if(ans[i]>=prev || ans[i]>=next){
                f1 = false;
                break;
            }
        }
    }

    sort(arr.begin(),arr.end());

    j = 0;
    for(int i=0;i<n;i+=2){
        ans[i] = arr[j++];
    }
    //j = n-1;
    for(int i=1;i<n;i+=2){
        ans[i] = arr[j++];
    }

    for(int i=0;i<n;i++){
        int prev, next;
        if(i%2!=0){
            if(i==0) prev = ans[n-1];
            else prev = ans[i-1];
            if(i==n-1) next = ans[0];
            else next = ans[i+1];

            if(ans[i]<=prev || ans[i]<=next){
                f1 = false;
                break;
            }
        }
        else{
            if(i==0) prev = ans[n-1];
            else prev = ans[i-1];
            if(i==n-1) next = ans[0];
            else next = ans[i+1];

            if(ans[i]>=prev || ans[i]>=next){
                f1 = false;
                break;
            }
        }
    }

    if(f1 && f2){
        cout << "YES" << endl;
        for(auto &x : ans) cout << x << " ";
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
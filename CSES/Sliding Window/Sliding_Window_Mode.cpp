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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    map<int,int> freq;
    multiset<pair<int,int>> mt;
    for(int i=0;i<n;i++){
        if(freq.count(arr[i])){
            mt.erase({-freq[arr[i]], arr[i]});
        }
        freq[arr[i]]++;
        mt.insert({-freq[arr[i]], arr[i]});
        if(i-k>=0){
            mt.erase({-freq[arr[i-k]], arr[i-k]});
            freq[arr[i-k]]--;
            if(freq[arr[i]] == 0){
                freq.erase(arr[i-k]);
            }
            else{
                mt.insert({-freq[arr[i-k]], arr[i-k]});
            }
        }
        if(i>=k-1){
            cout << mt.begin()->second << " ";
        }
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}
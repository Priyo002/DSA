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

int n, cnt;
string s;

bool check(int len){
    unordered_map<char,int> freq;
    for(int i=0;i<n;i++){
        freq[s[i]]++;
        if(i-len>=0){
            freq[s[i-len]]--;
            if(freq[s[i-len]] == 0){
                freq.erase(s[i-len]);
            }
        }
        if(i>=len-1){
            if(freq.size() == cnt) return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> s;

    set<char> st(s.begin(), s.end());
    cnt = st.size();

    int lo = 1, hi = n;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}
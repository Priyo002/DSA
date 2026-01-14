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
    
    string p,s;
    cin >> p >> s;

    int n = p.size(), m = s.size();

    if(m<n){
        cout << "NO" << endl;
        return;
    }

    vector<pair<char,int>> arr, brr;

    for(int i=0;i<n;i++){
        int j = i;
        int cnt = 0;
        while(j<n && p[j] == p[i]){
            cnt++;
            j++;
        }
        i = j - 1;
        arr.push_back({p[i], cnt});
    }

    for(int i=0;i<m;i++){
        int j = i;
        int cnt = 0;
        while(j<m && s[j] == s[i]){
            cnt++;
            j++;
        }
        i = j - 1;
        brr.push_back({s[i], cnt});
    }


    if(arr.size() != brr.size()){
        cout << "NO" << endl;
        return;
    }

    for(int i=0;i<arr.size();i++){
        if(arr[i].first != brr[i].first){
            cout << "NO" << endl;
            return;
        }

        if(arr[i].second > brr[i].second || arr[i].second * 2 < brr[i].second){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
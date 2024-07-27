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
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

void solve(){
    int n,q;
    cin >> n >> q;

    string s1,s2;
    cin >> s1 >> s2;

    vector<vector<int>> arr(n,vector<int>(26,0));
    vector<vector<int>> brr = arr;

    for(int i=0;i<n;i++){
        arr[i][s1[i]-'a']++;
        brr[i][s2[i]-'a']++;
        if(i){
            for(int j=0;j<26;j++){
                arr[i][j] += arr[i-1][j];
                brr[i][j] += brr[i-1][j];
            }
        }
    }

    while(q--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        
        vector<int> a = arr[r], b = brr[r];
        if(l){
            for(int j=0;j<26;j++){
                a[j] -= arr[l-1][j];
                b[j] -= brr[l-1][j];
            }
        }

        int ans = 0;

        for(int i=0;i<26;i++){
            if(a[i]>=b[i]) a[i] -= b[i];
            else{
                a[i] = 0;
            }
            ans += a[i];
        }

        cout << ans << endl;
    }
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
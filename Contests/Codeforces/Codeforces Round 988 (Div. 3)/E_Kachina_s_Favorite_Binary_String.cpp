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

    int prevCnt,total;
    int l = 1;

    cout << "? " << l << " " << n << endl;
    cout.flush();

    cin >> prevCnt;
    total = prevCnt;

    if(prevCnt == 0){
        cout << "! IMPOSSIBLE" << endl;
        cout.flush();
        return;
    }

    string ans = "";

    while(l<n){
        l++;
        if(l==n) break;
        cout << "? " << l << " " << n << endl;
        cout.flush();

        int currCnt;
        cin >> currCnt;

        if(currCnt == 0){
            ans += "01";
            prevCnt = 0;
            break;
        }
        if(currCnt < prevCnt){
            ans += '0';
        }
        else{
            ans += '1';
        }
        prevCnt = currCnt;
    }

    if(prevCnt) ans += '0';

    int m = ans.size();
    int one = 0;
    for(int i=m-1;i>=0;i--){
        if(ans[i] == '1') one++;
        else total -= one;
    }

    int zero = m - one;
    while(zero && total>0){
        ans += '1';
        total -= zero;
    }

    while(ans.size()!=n){
        ans += '0';
    }

    cout << "! " << ans << endl;
    cout.flush();
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
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

int n, N;
int num;

int f(int level){
    if(level == N){
        if(num<=n){
            string s = to_string(num);
            bool flag3 = false, flag5 = false, flag7 = false;
            for(char &ch : s){
                if(ch == '3') flag3 = true;
                else if(ch == '5') flag5 = true;
                else if(ch == '7') flag7 = true;
            }
            return (flag3 && flag5 && flag7);
        }
        return 0;
    }   

    int cnt = 0;
    num *= 10;
    num += 3;
    cnt += f(level + 1);
    num /= 10;

    num *= 10;
    num += 7;
    cnt += f(level + 1);
    num /= 10;

    num *= 10;
    num += 5;
    cnt += f(level + 1);
    num /= 10;

    return cnt;
}

void solve(){
    cin >> n;

    int noOfDigit = to_string(n).size();
    
    int ans = 0;
    for(int i=1;i<=noOfDigit;i++){
        N = i;
        num = 0;
        ans += f(0);
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
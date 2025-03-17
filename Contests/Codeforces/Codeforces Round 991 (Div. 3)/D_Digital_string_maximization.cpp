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
    string s;
    cin >> s;

    string ans = "";
    ans += s[0];

    int n = s.size();
    for(int i=1;i<n;i++){
        if(s[i] == '0' || s[i] == '1'){
            ans += s[i];
            continue;
        }
        
        int num = (s[i]-'0');
        int j = i-1;
        num--;
        int idx = -1, t = -1;

        while(j>=0 && num>0){
            int k = ans[j]-'0';
            if(k<num){
                idx = j;
                t = num;
            }
            j--;
            num--;
        }

        if(idx==-1){
            ans += s[i];
        }
        else{
            ans += '.';
            for(int l=ans.size()-1;l>idx;l--){
                swap(ans[l],ans[l-1]);
            }
            ans[idx] = char(t+'0');
        }
    }   
    cout << ans << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
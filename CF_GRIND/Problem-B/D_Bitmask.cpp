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
    string s;
    cin >> s;
    int n;
    cin >> n;

    reverse(s.begin(),s.end());

    int num = 0;
    for(int i=s.size()-1;i>=0;i--){
        int temp = num;
        if(s[i]=='?'){
            if((temp|(1LL<<i))<=n){
                temp |= (1LL<<i);
            }
        }
        else if(s[i]=='1'){
            temp |= (1LL<<i);
        }
        num = temp;
    }
    if(num>n){
        for(int i=0;i<s.size();i++){
            if(s[i]=='?' && ((num>>i)&1)){
                num ^= (1LL<<i);
            }
            if(num<=n){
                for(int i=s.size()-1;i>=0;i--){
                    if(s[i]=='?' && !((num>>i)&1)){
                        int t = num;
                        if((t|(1LL<<i))<=n){
                            t |= (1LL<<i);
                        }
                        num = t;
                    }
                }
                cout << num ;
                return;
            }
        }
        cout << -1;
    }
    else cout << num;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
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
    int n,q;
    cin >> n >> q;

    string s;
    cin >> s;

    int cnt = 0;

    for(int i=0;i<=n-3;i++){
        string t = s.substr(i,3);
        if(t=="ABC") cnt++;
    }

    while(q--){
        int i;
        cin >> i;
        i--;
        char ch;
        cin >> ch;

        if(ch==s[i]){
            cout << cnt << endl;
        }
        else{
            char now = s[i];
            if(now=='A'){
                if(i<=n-3){
                    string t = s.substr(i,3);
                    if(t=="ABC") cnt--;
                }
            }
            else if(now=='B'){
                if(i>0){
                    string t = s.substr(i-1,3);
                    if(t=="ABC") cnt--;
                }
            }
            else if(now=='C'){
                if(i>1){
                    string t = s.substr(i-2,3);
                    if(t=="ABC") cnt--;
                }
            }

            s[i] = ch;
            now = s[i];

            if(now=='A'){
                if(i<=n-3){
                    string t = s.substr(i,3);
                    if(t=="ABC") cnt++;
                }
            }
            else if(now=='B'){
                if(i>0){
                    string t = s.substr(i-1,3);
                    if(t=="ABC") cnt++;
                }
            }
            else if(now=='C'){
                if(i>1){
                    string t = s.substr(i-2,3);
                    if(t=="ABC") cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
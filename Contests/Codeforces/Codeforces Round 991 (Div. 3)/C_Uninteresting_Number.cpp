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

    int sum = 0;
    int two = 0, three = 0;
    for(auto &ch : s){
        sum += (ch-'0');
        if(ch=='2') two++;
        if(ch=='3') three++;
    }

    if(sum%9 == 0){
        cout << "YES" << endl;
    }
    else{
        int need = sum%9;

        if(need%2 == 0){
            if(need == 2){
                if((three>=2 && two>=2) || (three>=1 && two>=5) || (two>=8)) cout << "YES";
                else cout << "NO";
            }
            else if(need == 4){
                if((three>=2 && two>=1) || (three>=1 && two>=4) || (two>=7)) cout << "YES";
                else cout << "NO";
            }
            else if(need == 6){
                if((three>=2 && two>=0) || (three>=1 && two>=3) || (two>=6)) cout << "YES";
                else cout << "NO";
            }
            else if(need == 8){
                if((three>=1 && two>=2) || (two>=5)) cout << "YES";
                else cout << "NO";
            }
        }
        else{
            if(need == 1){
                if((three>=1 && two>=1) || (two>=4)) cout << "YES";
                else cout << "NO";
            }
            else if(need == 3){
                if((three>=1 && two>=0) || (two>=3)) cout << "YES";
                else cout << "NO";
            }
            else if(need == 5){
                if((two>=2)) cout << "YES";
                else cout << "NO";
            }
            else if(need == 7){
                if(two>=1) cout << "YES";
                else cout << "NO";
            }   
        }
        cout << endl;
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
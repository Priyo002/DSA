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
    
    int b,c,d;
    cin >> b >> c >> d;

    int a = 0;
    for(int i=0;i<62;i++){
        int bitB = ((b>>i)&1);
        int bitC = ((c>>i)&1);
        int bitD = ((d>>i)&1);

        if((bitB==0 && bitC==1 && bitD==1) || (bitB==1 && bitC==0 && bitD==0)){
            cout << -1 << endl;
            return;
        }

        if(bitD==0){
            if(bitB==0 && bitC==1) a |= (1LL<<i);
            else if(bitB==1 && bitC==1) a |= (1LL<<i); 
        }
        else{   
            if(bitB==0 && bitC==0) a |= (1LL<<i);
        }
    }
    cout << a << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
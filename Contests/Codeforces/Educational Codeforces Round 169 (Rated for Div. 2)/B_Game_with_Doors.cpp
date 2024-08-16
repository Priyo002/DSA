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
    int al,ar,bl,br;
    cin >> al >> ar >> bl >> br;

    
    if(al==bl && ar==br){
        cout << br-al << endl;
        return;
    }
    if(al==bl){
        cout << min(br,ar) - al+1 << endl;
        return;
    }
    if(ar==br){
        cout << br-max(al,bl)+1 << endl;
        return;
    }
    if(bl>=al && bl<=ar){
        if(br<=ar){
            cout << br-bl+2 << endl;
        }
        else{
            cout << ar-bl+2 << endl;
        }
        return;
    }
    if(al>=bl && al<=br){
        if(ar<=br){
            cout << ar-al+2 << endl;
        }
        else{
            cout << br-al+2 << endl;
        }
        return;
    }
    cout << 1 << endl;
    return;
    
}   

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
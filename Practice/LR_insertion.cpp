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

    string s;
    cin >> s;

    vector<int> arr = {0};
    int curr = 1;
    for(char &ch : s){
        if(ch == 'L'){
            int val1 = arr.back();
            arr.pop_back();
            if(arr.size()){
                int val2 = arr.back();
                arr.pop_back();
                arr.push_back(curr);
                arr.push_back(val2);
                arr.push_back(val1);
            }
            else{
                arr.push_back(curr);
                arr.push_back(val1);
            }
        }
        else{
            int val = arr.back();
            arr.pop_back();
            arr.push_back(curr);
            arr.push_back(val);
        }
        curr++;
    }

    for(int &x : arr){
        cout << x << " ";
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}
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

    if(n&1){
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    int i = 0, j = n-1;
   
    while(i<j){
        if(s[i]== s[j]){
            if(s[i] == '1'){
                s.insert(s.begin()+i,'1');
                s.insert(s.begin()+i,'0');
                ans.push_back(i);
                j++;
                i++;
            }
            else{
                s.insert(s.begin()+j+1,'1');
                s.insert(s.begin()+j+1,'0');
                ans.push_back(j+1);
                j++;
                i++;
            }
        }
        else{
            i++, j--;
        }
        if((int)ans.size()>300){
            cout << -1 << endl;
            return;
        }
    }

    cout << (int)ans.size() << endl;
    for(auto &x : ans) cout << x << " ";
    cout << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
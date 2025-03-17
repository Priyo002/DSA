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

string s = "ABCDE";

void solve(){
    vector<int> arr(5);
    for(int i=0;i<5;i++) cin >> arr[i];

    vector<string> ans;
    for(int i=1;i<(1<<5);i++){
        string str = "";
        for(int j=0;j<5;j++){
            if((i>>j)&1){
                str += s[j];
            }
        }
        ans.push_back(str);
    }

    sort(ans.begin(),ans.end(),[&arr](string &a,string &b){
        int scoreA = 0, scoreB = 0;
        for(auto &ch : a){
            scoreA += arr[ch-'A'];
        }
        for(auto &ch : b){
            scoreB += arr[ch-'A'];
        }
        if(scoreA == scoreB) return a < b;
        return scoreA > scoreB;
    });

    for(auto &str : ans) cout << str << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
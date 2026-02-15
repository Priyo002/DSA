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
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    unordered_set<int> s1(s.begin(), s.end()), s2(t.begin(), t.end());

    int q;
    cin >> q;

    while(q--){
        string str;
        cin >> str;

        int len = str.size();

        int cnt1 = false, cnt2 = false;
        for(char &ch : str){
            if(s1.count(ch)){
                cnt1++;
            }
            if(s2.count(ch)){
                cnt2++;
            }
        }

        if(cnt1 == len && cnt2 == len){
            cout << "Unknown";
        }
        else if(cnt1 == len){
            cout << "Takahashi";
        }
        else{
            cout << "Aoki";
        }
        cout << endl;
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
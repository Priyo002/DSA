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
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    int m;
    cin >> m;

    string s;
    while(m--){
        cin >> s;
        if((int)s.size()!=n){
            cout << "NO" << endl;
            continue;
        }
        map<int,int> mp1,mp2;
        bool flag = true;

        for(int i=0;i<n;i++){
            int num = arr[i];
            int idx = s[i]-'a';
            
            if(mp1.find(num)!=mp1.end() && mp1[num]!=idx){
                flag = false;
                break;
            }
            if(mp2.find(idx)!=mp2.end() && mp2[idx]!=num){
                flag = false;
                break;
            }
            mp1[num] = idx;
            mp2[idx] = num;
        }
        if(flag) cout << "YES";
        else cout << "NO";
        cout << endl;
    }   
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
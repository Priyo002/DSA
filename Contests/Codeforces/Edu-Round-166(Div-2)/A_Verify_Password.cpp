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

    string s;
    cin >> s;

    string digit = "", alpha = "";

    vector<int> digIdx, alphaIdx;

    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            digit += s[i];
            digIdx.push_back(i);
        }
        else{
            alpha += s[i];
            alphaIdx.push_back(i);
        }
    }

    bool flag = true;

    if(digIdx.size() && alphaIdx.size() && digIdx.back()>=alphaIdx[0]){
        flag = false;
    }

    bool f1 = is_sorted(digit.begin(),digit.end());
    bool f2 = is_sorted(alpha.begin(),alpha.end());

    if(!(flag && f1 && f2)){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
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
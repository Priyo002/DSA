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

int f(string &str){
    int n = str.size();
    int score = 0;
    for(int i=0;i<n;i++){
        if(i==0) score += 2;
        else{
            if(str[i-1]==str[i]) score++;
            else score += 2;
        }
    }
    return score;
}

void solve(){
    string s;
    cin >> s;

    int mxScore = 0;
    string ans = s;
    int n = s.size();
    for(char ch='a';ch<='z';ch++){
        string temp = s;
        for(int i=0;i<=n;i++){
            temp.insert(temp.begin()+i,ch);
            int score = f(temp);
            if(score>mxScore){
                mxScore = score;
                ans = temp;
            }
            temp = s;
        }
    }

    cout << ans << endl;
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
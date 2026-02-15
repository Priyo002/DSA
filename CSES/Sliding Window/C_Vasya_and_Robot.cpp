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

int n, tx, ty;
string s;
vector<int> total;

bool check(int len){
    int cntR = 0, cntL = 0, cntU = 0, cntD = 0;
    for(int i=0;i<n;i++){

        if(s[i] == 'R') cntR++;
        else if(s[i] == 'L') cntL++;
        else if(s[i] == 'U') cntU++;
        else cntD++;
        
        if(i-len>=0){
            if(s[i-len] == 'R') cntR--;
            else if(s[i-len] == 'L') cntL--;
            else if(s[i-len] == 'U') cntU--;
            else cntD--;
        }

        if(i>=len-1){
            int leftR = total[0] - cntR;
            int leftL = total[1] - cntL;
            int leftU = total[2] - cntU;
            int leftD = total[3] - cntD;

            int currX = leftR - leftL, currY = leftU - leftD;
            int xReq = abs(tx - currX), yReq = abs(ty - currY);
            
            if(xReq + yReq <= len){
                int diff = len - (xReq + yReq);
                if(diff%2 == 0) return true;
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> s;
    cin >> tx >> ty;

    total.assign(4, 0); // R, L, U, D

    for(char &ch : s){
        if(ch == 'R') total[0]++;
        else if(ch == 'L') total[1]++;
        else if(ch == 'U') total[2]++;
        else total[3]++;
    }

    int lo = 0, hi = n;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}
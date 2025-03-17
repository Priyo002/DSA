#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define endl '\n'
const int mod = 1e9+7;
const long long INF = 1e18;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string str;
int nb, ns, nc;
int pb, ps, pc;
int rubles;
int b, s, c;

bool check(int hm){

    int reqB = hm*b;
    int reqS = hm*s;
    int reqC = hm*c;

    reqB -= nb;
    reqS -= ns;
    reqC -= nc;

    int cost = max(0LL,reqB)*pb;
    if(cost > rubles) return false;
    cost += max(0LL,reqS)*ps;
    if(cost > rubles) return false;
    cost += max(0LL,reqC)*pc;

    return cost<=rubles;
}

void solve(){
    cin >> str;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> rubles;

    b = s = c = 0;
    
    for(auto &ch : str){
        if(ch=='B') b++;
        else if(ch == 'S') s++;
        else c++;
    }

    int ans = 0;
    int lo = 1, hi = 1e14;

    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
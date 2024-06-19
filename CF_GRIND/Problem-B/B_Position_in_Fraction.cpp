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


vector<bool> isPrime;
vector<int> spf;
void sieve(int N){
    isPrime.clear();
    isPrime.resize(N+1,true); 
    spf.clear();
    spf.resize(N+1);
    for(int i=2;i<=N;i++) spf[i] = i;
    spf[0] = spf[1] = -1;
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<=N;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=N;j+=i){
                if(isPrime[j]){
                  isPrime[j] = false;
                  spf[j] = i;
                }
            }
        }
    }
}

vector<int> getPrimeFactors(int n){
    vector<int> temp;
    while(spf[n]!=1){
        temp.push_back(spf[n]);
        n /= spf[n];
    }
}


void solve(){
    long double a,b,c;
    cin >> a >> b >> c;

    long double k = a/b;
    string s = to_string(k);

    bool f = true;

    if(s.find('.')!=string::npos){
        bool flag = false;
        int idx = -1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                flag = true;
            }
            if(flag && s[i]==(char)('0'+c)){
                idx = i;
                break;
            }
        }
        if(idx!=-1 && (f || idx!=s.size()-1)){

        }
    }
    cout << s << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    sieve(100100);
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
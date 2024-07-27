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
bool kk = false;
void sieve(int N){
    if(kk) return;
    kk = true;
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

set<int> getPrimeFactors(int n){
    set<int> temp;
    while(n!=1){
        temp.insert(spf[n]);
        n /= spf[n];
    }
    return temp;
}


void solve(){
    long double a,b,c;
    cin >> a >> b >> c;

    long double k = a/b;
    string s = to_string(k);

    set<int> st = getPrimeFactors(b);

    bool f = st.count(3) || st.count(5);

    if(s.find('.')!=string::npos){
        string str = "";
        bool flag = false;
        for(int i=0;i<s.size();i++){
            if(flag){
                str += s[i];
            }
            if(s[i]=='.') flag = true;
        }

        for(int i=0;i<str.size();i++){
            if(str[i]==(char)(c+'0')){
                if(f && i==str.size()-1){
                    if(str[i]==(char)((c+1)+'0')) cout << i+1 << endl;
                    else cout << -1 << endl;
                    return;
                }
                else{
                    cout << i+1 << endl;
                    return;
                }
            }
        }
        cout << -1 << endl;
    }
    else{
        cout << -1 << endl;
    }
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
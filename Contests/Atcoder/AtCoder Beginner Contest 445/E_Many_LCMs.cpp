#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int mod = 998244353;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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

unordered_map<int,int> getPrimeFactors(int x){
    unordered_map<int,int> freq;
    while(x>1){
        int cnt = 0;
        int t = spf[x];
        while(x%t == 0){
            cnt++;
            x /= t;
        }
        freq[t] = cnt;
    }
    return freq;
}

unordered_map<int,int> merge(unordered_map<int,int>& a, unordered_map<int,int>& b){
    unordered_map<int,int> temp;
    for(auto &x : a){
        if(b.count(x.first)){
            temp[x.first] = max(x.second, b[x.first]);
        }
        else{
            temp[x.first] = x.second;
        }
    }
    for(auto &x : b){
        if(!temp.count(x.first)){
            temp[x.first] = x.second;
        }
    }
    return temp;
}

int power(int a,int b,int MOD){
    int res = 1;
    while(b){
        if(b&1){
            res = ((res%MOD)*(a%MOD))%MOD;
        }
        a = ((a%MOD)*(a%MOD))%MOD;
        b = (b>>1);
    }
    return (res%MOD);
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }   

    vector<unordered_map<int,int>> primeFactors(n);
    for(int i=0;i<n;i++){
        primeFactors[i] = getPrimeFactors(arr[i]);
    }

    vector<unordered_map<int,int>> pref(n), suff(n);
    pref[0] = primeFactors[0];
    for(int i=1;i<n;i++){
        pref[i] = merge(primeFactors[i], pref[i-1]);
    }

    suff[n-1] = primeFactors[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i] = merge(primeFactors[i], suff[i+1]);
    }

    for(int i=0;i<n;i++){
        if(i==0){
            int ans = 1;
            for(auto &x : suff[i+1]){
                ans *= power(x.first, x.second, mod);
                ans %= mod;
            }
            cout << ans << " ";
        }
        else if(i==n-1){
            int ans = 1;
            for(auto &x : pref[i-1]){
                ans *= power(x.first, x.second, mod);
                ans %= mod;
            }
            cout << ans << " ";
        }
        else{
            unordered_map<int,int> temp = merge(pref[i-1], suff[i+1]);
            int ans = 1;
            for(auto &x : temp){
                ans *= power(x.first, x.second, mod);
                ans %= mod;
            }
            cout << ans << " ";
        }
    }
    cout << endl;
}

int32_t main(){
    
    init();

    sieve(10000001);

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    return 0;
}
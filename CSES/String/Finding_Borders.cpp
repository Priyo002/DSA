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

struct Hasher{
    int n;
    string s;
    long long p,mod;
    vector<long long> prefixHash,suffixHash,pk;
    void init(string s,long long p,long long mod){
        this->p = p;//base
        this->mod = mod;
        this->s = s;
        n = s.size();
        prefixHash.clear(), suffixHash.clear();
        prefixHash.resize(n);
        suffixHash.resize(n);
        pk.resize(n);

        pk[0] = 1;
        prefixHash[0] = s[0]-'a'+1;
        for(int i=1;i<n;i++){
            prefixHash[i] = ((prefixHash[i-1]*p)%mod + (s[i]-'a'+1))%mod;
            pk[i] = (pk[i-1]*p)%mod;
        }

        suffixHash[n-1] = s[n-1]-'a'+1;
        for(int i=n-2;i>=0;i--){
            suffixHash[i] = ((suffixHash[i+1]*p)%mod + (s[i]-'a'+1))%mod;
        }
    }
    long long getHash(int l,int r){//0-indexed
        if(l==0) return prefixHash[r];
        return ((prefixHash[r] - (prefixHash[l-1]*pk[r-l+1])%mod) + mod)%mod;
    }
    long long getRevHash(int l,int r){
        if(r==n-1) return suffixHash[l];
        return ((suffixHash[l] - (suffixHash[r+1]*pk[r-l+1])%mod)+ mod)%mod;
    }
};

void solve(){

    string s;
    cin >> s;

    Hasher hash;
    hash.init(s,31,1e9+9);

    int n = s.size();

    for(int i=0;i<n-1;i++){
        long long pref = hash.getHash(0,i);
        long long suff = hash.getHash(n-1-i,n-1);
        if(pref==suff){
            cout << i+1 << " ";
        }
    }
    
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
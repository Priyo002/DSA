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


//using Rolling Hash
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
    int n;
    string s;
    Hasher hash1,hash2;

    cin >> s;
    n = s.size();

    hash1.init(s,37,1e9+7);
    hash2.init(s,39,1e9+9);

    int ans = 0;
    string str;
    int idx = -1;
    bool odd = false, even = false;
    for(int i=0;i<n;i++){
        //odd max palindrome length check
        int lo = 1, hi = min(i+1,n-i);
        int mxLen = 1;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(hash1.getHash(i-mid+1,i) == hash1.getRevHash(i,i+mid-1) && hash2.getHash(i-mid+1,i) == hash2.getRevHash(i,i+mid-1)){
                mxLen = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        if(2*mxLen-1>ans){
            ans = 2*mxLen-1;
            idx = i;
            odd = true;
            even = false;
        }

        //even max palindrome length check
        if(i==0) continue;
        
        lo = 1, hi = min(i,n-i);
        mxLen = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(hash1.getHash((i-1)-mid+1,i-1) == hash1.getRevHash(i,i+mid-1) && hash2.getHash((i-1)-mid+1,i-1) == hash2.getRevHash(i,i+mid-1)){
                mxLen = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        if(2*mxLen>ans){
            ans = 2*mxLen;
            idx = i;
            odd = false;
            even = true;
        }
    }
    if(odd){
        int mxLen = (ans+1)/2;
        str = s.substr(idx-mxLen+1,2*mxLen-1);
    }
    else{
        int mxLen = ans/2;
        str = s.substr(idx-mxLen,2*mxLen);
    }

    cout << str << endl;
    
}




//Using Manacher Algorithm
struct manacher{
    vector<int> p;
    void runManacher(string s){
        int n = s.size();
        p.assign(n,1);
        int l = 1, r = 1;//l and r not inclusive
        for(int i=1;i<n;i++){
            p[i] = max(0LL,min(r-i,p[max(0LL,l+r-i)]));
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }
    void build(string s){
        string t;
        for(auto &v : s){
            t += "#";
            t += v;
        }
        t += "#";
        runManacher(t);
    }
    int getLongest(int center,bool odd){
        int posInP = 2*center + 1 + (!odd);
        return p[posInP]-1;
    }
    bool isPali(int l,int r){
        int len = r-l+1;
        bool odd = (l%2)==(r%2);
        int center = l+(r-l)/2;
        return len<=getLongest(center,odd);
    }
};

void solve2(){
    string s;
    cin >> s;

    manacher mn;
    mn.build(s);

    int n = s.size();
    int idx = 0, mxLen = 1;

    for(int i=0;i<n;i++){
        int len = mn.getLongest(i,true);
        if(len>mxLen){
            mxLen = len;
            int halfLen = (len+1)/2;
            idx = i-halfLen+1;
        }
        if(i==n-1) continue;
        len = mn.getLongest(i,false);
        if(len>mxLen){
            mxLen = len;
            int halfLen = len/2;
            idx = i-halfLen+1;
        }
    }
    cout << s.substr(idx,mxLen);
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve2();


    return 0;
}
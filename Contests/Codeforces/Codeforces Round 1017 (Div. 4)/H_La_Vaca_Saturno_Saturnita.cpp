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

void solve(){
    int n,q;
    cin >> n >> q;

    vector<int> arr(n);
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }

    while(q--){
        int k,l,r;
        cin >> k >> l >> r;
        l--, r--;

        int ans = 0;
        for(int i=l;i<=r;i++){
            while(k%arr[i] == 0){
                k /= arr[i];
            }
            ans += k;
            if(isPrime[k]){
                if(mp.count(k)){
                    int idx = upper_bound(mp[k].begin(),mp[k].end(),i) - mp[k].begin();
                    if(idx != mp[k].size()){
                        int t = mp[k][idx];
                        if(t<=r && t>i){
                            ans += (k*max(0LL,t - i - 1)) + (r - t + 1);
                        }
                        else{
                            ans += k*(r - i);
                        }
                    }
                    else{
                        ans += k*(r - i);
                    }
                }
                else{
                    ans += k*(r - i);
                }
                break;
            }
        }
        cout << ans << endl;
    }

   

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;

    sieve(100010);

    while(_t--)
        solve();


    return 0;
}
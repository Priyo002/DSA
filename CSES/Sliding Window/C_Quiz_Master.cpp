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

int n, m;
vector<int> arr;
vector<vector<int>> factors;

void preCompute(){
    factors.assign(100001, vector<int>());

    for(int i=1;i<=100000;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j == 0){
                factors[i].push_back(j);
                if(i/j != j){
                    factors[i].push_back(i/j);
                }
            }
        }
    }
    for(int i=1;i<=100000;i++){
        sort(factors[i].begin(), factors[i].end());
    }
}

bool check(int diff){
    int head = -1, tail = 0;
    vector<int> freq(m+1, 0);
    int cnt = 0;
    while(tail<n){
        while(head+1<n && arr[head+1] - arr[tail] <= diff){
            head++;
            for(int &x : factors[arr[head]]){
                if(x > m) break;
                freq[x]++;
                if(freq[x] == 1){
                    cnt++;
                }
            }
        }
        if(cnt == m) return true;
        if(tail<=head){
            for(int &x : factors[arr[tail]]){
                if(x > m) break;
                freq[x]--;
                if(freq[x] == 0){
                    cnt--;
                }
            }
            tail++;
        }
        else{
            tail++;
            head = tail - 1;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;

    arr.assign(n, -1);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int lo = 0, hi = arr[n-1] - arr[0];
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
    // cout << check(0) << endl; 
    cout << ans << endl;
}

int32_t main(){
    
    init();

    preCompute();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    return 0;
}
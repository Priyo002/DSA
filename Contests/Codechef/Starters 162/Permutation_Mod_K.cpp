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

void f(vector<int>& arr,int i,int j){
    int len = j-i+1;
    int ni = i, nj = j;
    while(ni<nj){
        swap(arr[ni++],arr[nj--]);
    }
    if(len&1){
        swap(arr[(i+j)/2],arr[(i+j)/2 + 1]);
    }
}

void solve(){
    
    int n,k;
    cin >> n >> k;

    if(k == 1 || (k==2 && n%2 == 1)){
        cout << -1 << endl;
        return;
    }

    vector<int> arr;
    for(int i=1;i<=n;i++) arr.push_back(i);

    if(k == 2){
        for(int i=0;i<n;i+=2){
            swap(arr[i],arr[i+1]);
        }
    }
    else{
        int i = 0, j = k-2;
        while(i<n){
            int len = j-i+1;
            if(len == 1){
                if(i == 0){
                    cout << -1 << endl;
                    return;
                }
                swap(arr[i],arr[i-1]);
                break;
            }
            f(arr,i,j);
            i = j+1;
            j += k;
            j = min(j,n-1);
        }
    }

    for(auto &x : arr) cout << x << " ";
    cout << endl;
    
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
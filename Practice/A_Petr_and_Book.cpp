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

void solve(){
    int n;
    cin >> n;

    int sum = 0;
    vector<int> arr(7, 0);
    for(int i=0;i<7;i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int week = n/sum;
    int pagesLeft = n - (sum*week);

    if(pagesLeft > 0){
        for(int i=0;i<7;i++){
            if(pagesLeft - arr[i] <= 0){
                cout << i+1;
                return;
            }
            pagesLeft -= arr[i];
        }
    }
    else{
        pagesLeft = n - (sum*(week - 1));
        for(int i=0;i<7;i++){
            if(pagesLeft - arr[i] <= 0){
                cout << i+1;
                return;
            }
            pagesLeft -= arr[i];
        }
    }

}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}
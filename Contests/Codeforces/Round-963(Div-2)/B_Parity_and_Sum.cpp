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

void solve(){
    int n;
    cin >> n;
    
    vector<int> arr(n);
    vector<int> even,odd;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]%2==0) even.push_back(arr[i]);
        else odd.push_back(arr[i]);
    }

    if(even.size()==0 || odd.size()==0){
        cout << 0 << endl;
        return;
    }

    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());

    int maxOdd = odd.back();

    int ans = 0;

    int idx = -1;
    int m = even.size();
    for(int i=0;i<m;i++){
        int x = even[i];
        if(x<maxOdd){
            ans++;
            maxOdd += x;
        }
        else{
            idx = i;
            break;
        }
    }
    if(idx!=-1){
        ans++;
        ans += (m-idx);
    }
    cout << ans << endl;
}   

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
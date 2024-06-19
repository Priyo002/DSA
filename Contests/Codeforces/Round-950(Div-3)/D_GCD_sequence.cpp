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

vector<int> f(vector<int> & arr){
    int n = arr.size();
    vector<int> res;
    for(int i=0;i<n-1;i++){
        res.push_back(__gcd(arr[i],arr[i+1]));
    }
    return res;
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n),gcd;

    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n-1;i++){
        gcd.push_back(__gcd(arr[i],arr[i+1]));
        //cout << gcd.back() << " ";
    }
    //cout << endl;


    if(is_sorted(gcd.begin(),gcd.end())){
        cout << "YES";
    }
    else{
        
        int m = gcd.size();
        int idx = -1;
        for(int i=1;i<m;i++){
            if(gcd[i]>=gcd[i-1]) continue;
            idx = i;
            break;
        }
        vector<int> t;
        for(int i=0;i<n;i++){
            if(i==idx-1) continue;
            t.push_back(arr[i]);
        }
        vector<int> g = f(t);

        bool f1 = is_sorted(g.begin(),g.end());

        t.clear();
        g.clear();

        for(int i=0;i<n;i++){
            if(i==idx) continue;
            t.push_back(arr[i]);
        }
        g = f(t);

        bool f2 = is_sorted(g.begin(),g.end());

        t.clear();
        g.clear();

        for(int i=0;i<n;i++){
            if(i==idx+1) continue;
            t.push_back(arr[i]);
        }

        g = f(t);

        bool f3 = is_sorted(g.begin(),g.end());

        if(f1 || f2 || f3) cout << "YES";
        else cout << "NO";
    }
    cout << endl;

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
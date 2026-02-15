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

int n;
vector<double> arr;

double getWeakness(double x) {
    double current_max = 0, max_so_far = -1e18;
    double current_min = 0, min_so_far = 1e18;
    
    for(int i=0;i<n;i++){
        double val = arr[i] - x;

        current_max += val;
        max_so_far = max(max_so_far, current_max);
        if(current_max < 0) current_max = 0;

        current_min += val;
        min_so_far = min(min_so_far, current_min);
        if(current_min > 0) current_min = 0;
    }

    return max(abs(max_so_far), abs(min_so_far));
}

bool check(double m1, double m2){
    return getWeakness(m1) >= getWeakness(m2);
}

void solve() {
    cin >> n;

    arr.assign(n, 0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    double lo = -10000, hi = 10000;
    double ans = -1;
    for(int i=0;i<100;i++){
        double m1 = lo + (hi - lo) / 3;
        double m2 = hi - (hi - lo) / 3;
        if(check(m1, m2)){
            ans = m1;
            lo = m1;
        } 
        else{
            hi = m2;
        }
    }

    cout << fixed << setprecision(10) << getWeakness(ans) << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}
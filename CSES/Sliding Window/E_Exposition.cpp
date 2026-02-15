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

int n, k;
vector<int> arr;

bool check(int val, multiset<int>& mt){
    mt.insert(val);
    int diff = *mt.rbegin() - *mt.begin();
    mt.erase(mt.find(val));
    return (diff<=k);
}

int getMaxLen(){
    int head = -1, tail = 0;
    int ans = 0;
    multiset<int> mt;
    while(tail<n){
        while(head+1<n && check(arr[head+1], mt)){
            head++;
            mt.insert(arr[head]);
        }
        ans = max(ans, head - tail + 1);
        if(tail<=head){
            mt.erase(mt.find(arr[tail]));
            tail++;
        }
        else{
            tail++;
            head = tail - 1;
        }
    }
    return ans;
}

void solve(){
    cin >> n >> k;

    arr.assign(n, -1);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int mxLen = getMaxLen();

    multiset<int> mt;
    vector<pair<int,int>> temp;

    for(int i=0;i<n;i++){
        mt.insert(arr[i]);
        if(i-mxLen>=0){
            mt.erase(mt.find(arr[i-mxLen]));
        }
        if(i>=mxLen-1){
            int diff = *mt.rbegin() - *mt.begin();
            if(diff<=k){
                temp.push_back({i-mxLen+1, i});
            }
        }
    } 

    cout << mxLen << " " << temp.size() << endl;
    for(auto &x : temp){
        cout << x.first+1 << " " << x.second+1 << endl;
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
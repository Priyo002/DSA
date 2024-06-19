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

int n,k;

vector<int> f(vector<int> &arr){
    
    vector<vector<int>> temp;
    for(int i=0;i<k;i++){
        int j = i;
        vector<int> t;
        while(j<n){
            t.push_back(arr[j]);
            j += k;
        }
        sort(t.begin(),t.end());
        temp.push_back(t);
    }
    
    vector<int> ans;

    for(int j=0;j<temp[0].size();j++){
        for(int i=0;i<temp.size();i++){
            if(j<temp[i].size())
                ans.push_back(temp[i][j]);
        }
    }

    return ans;
}

void solve(){
    
    cin >> n >> k;

    vector<int> arr(n);

    map<int,set<int>> mp;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        mp[i%k].insert(arr[i]);
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        if(mp[i%k].find(i+1)==mp[i%k].end()){
            cnt++;
        }
    }

    if(cnt==0) cout << 0;
    else if(cnt==2) cout << 1;
    else cout << -1;
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
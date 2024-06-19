#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 998244353;
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

vector<vector<int>> arr;
int n;
bool check(int i,int j){
    set<int> st;
    if(i){
        for(int k=0;k<26;k++){
            if(arr[i-1][k]){
                st.insert(k);
            }
        }
    }
    for(int k=0;k<26;k++){
        if((arr[n-1][k]-arr[j][k])>0){
            st.insert(k);
        }
    }
    return (st.size()>1);
}

void solve(){
    
    cin >> n;

    string s;
    cin >> s;

    arr.clear();
    arr.resize(n,vector<int>(26,0));
 
    for(int i=0;i<n;i++){
        arr[i][s[i]-'a']++;
        if(i){
            for(int j=0;j<26;j++){
                arr[i][j] += arr[i-1][j];
            }
        }
    }

    int tail = 0, head = -1;
    int ans = 0,flag = 0, temp = -1;
    map<int,int> mp;

    vector<int> arr(26,0);

    while(tail<n){
        while(head+1<n && check(tail,head+1)){
            head++;
            arr[s[head]-'a']++;
        }
        if(head+1<n){
            if(tail==0){
                flag = 1;
                temp = head+1;
            }
            mp[head+1] = max(mp[head+1],tail);
        }
        if(tail<=head){
            tail++;
        }
        else{
            tail++;
            head = tail-1;
        }
    }
    for(auto x : mp){
        int i = x.second, idx = x.first;
        if(flag && idx==temp){
            ans += ((i+1)*(n-idx));
        }
        else{
            ans += (i*(n-idx));
        }
        ans %= mod;
    }
    cout << (ans%mod) << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
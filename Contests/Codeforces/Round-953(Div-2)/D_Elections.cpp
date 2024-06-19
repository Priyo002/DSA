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
    int n,c;
    cin >> n >> c;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> pge(n,-1), nge(n,-1);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(st.size() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.size()){
            nge[i] = st.top();
        }
        else{
            st.push(arr[i]);
        }
    }
    while(st.size()) st.pop();

    for(int i=0;i<n;i++){
        while(st.size() && st.top()<arr[i]){
            st.pop();
        }
        if(st.size()){
            pge[i] = st.top();
        }
        else{
            st.push(arr[i]);
        }
    }  

    vector<int> pref = arr;
    for(int i=1;i<n;i++){
        pref[i] += pref[i-1];
    }

    // for(int i=0;i<n;i++){
    //     cout << pge[i] << " ";
    // }
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     cout << nge[i] << " ";
    // }
    // cout << endl;

    vector<int> ans;

    for(int i=0;i<n;i++){
        if(pge[i]==-1 && nge[i]==-1){
            if(i && arr[0]+c>=arr[i]){
                ans.push_back(i);
            }
            else{
                ans.push_back(0);
            }
        }
        else if((pge[i]!=-1 && nge[i]!=-1)){
            if(pref[i]+c>=nge[i]){
                ans.push_back(i);
            }
            else{
                ans.push_back(i+1);
            }
        }
        else if(nge[i]!=-1 && pge[i]==-1){
            if(i==0){
                if(arr[0]+c>=nge[i]) ans.push_back(0);
                else ans.push_back(1);
            }
            else{
                if(pref[i]+c>=nge[i]){
                    ans.push_back(i);
                }
                else{
                    ans.push_back(i+1);
                }
            }
        }
        else if(pge[i]!=-1){
            ans.push_back(i);
        }
    }

    for(auto x : ans) cout << x << " ";
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
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
    int p,t;
    cin >> p >> t;

    int n = p+t+1;
    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++)cin >> arr[i].first;
    for(int i=0;i<n;i++) cin >> arr[i].second;

    int cntP = 0, cntT = 0;

    map<int,char> mp;
    set<int,greater<int>> prog,test;

    int skill = 0;
    for(int i=1;i<n;i++){
        int ps = arr[i].first;
        int ts = arr[i].second;

        if(ps>ts){
            if(cntP+1<=p){
                skill += ps;
                cntP++;
                prog.insert(i);
                mp[i] = 'p';
            }
            else{
                skill += ts;
                cntT++;
                test.insert(i);
                mp[i] = 't';
            }
        }
        else{
            if(cntT+1<=t){
                skill += ts;
                cntT++;
                test.insert(i);
                mp[i] = 't';
            }
            else{
                skill += ps;
                cntP++;
                prog.insert(i);
                mp[i] = 'p';
            }
        }
    }
    
    // for(auto x : prog){
    //     cout << "p" << x << " ";
    // }
    // cout << endl;
    // for(auto x : test){
    //     cout << "t" << x << " ";
    // }
    // cout << endl;
    vector<int> ans;

    ans.push_back(skill);

    for(int i=1;i<n;i++){
        char ch = mp[i];
        mp.erase(i);

        if(ch=='p'){
            cntP--;
            prog.erase(i);
            skill -= arr[i].first;
        }
        else{
            cntT--;
            test.erase(i);
            skill -= arr[i].second;
        }

        int ps = arr[i-1].first;
        int ts = arr[i-1].second;

        if(ps>ts){
            mp[i-1] = 'p';
            skill += ps;
            prog.insert(i-1);
            cntP++;
        }
        else{
            mp[i-1] = 't';
            skill += ts;
            test.insert(i-1);
            cntT++;
        }

        if(cntP==p && cntT==t){
            ans.push_back(skill);
            continue;
        }

        if(cntP<p){
            int idx = *test.begin();
            test.erase(idx);
            
            prog.insert(idx);
            mp[idx] = 'p';

            cntP++;
            cntT--;

            skill -= arr[idx].second;
            skill += arr[idx].first;
        }
        else if(cntT<t){
            int idx = *prog.begin();

            prog.erase(idx);
            
            test.insert(idx);
            mp[idx] = 't';

            cntP--;
            cntT++;

            skill -= arr[idx].first;
            skill += arr[idx].second;
        }
       
        // cout << endl;
        // for(auto x : prog){
        //     cout << "p" << x << " ";
        // }
        // cout << endl;
        // for(auto x : test){
        //     cout << "t" << x << " ";
        // }
        // cout << endl;
        ans.push_back(skill);
    }

    for(auto x : ans){
        cout << x << " ";
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
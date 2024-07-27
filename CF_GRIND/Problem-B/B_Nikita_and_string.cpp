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

struct Union_Find{
    int sz,cc;
    vector<int> par,rank;
    void init(int n){
        sz = n;
        cc = n;
        par.clear();
        rank.clear();
        par.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=sz;i++){
            par[i] = i;
        }
    }
    int findParent(int x){
        if(x==par[x]) return x;
        else return par[x] = findParent(par[x]);
    }
    void addEdge(int x,int y){
        int parX = findParent(x);
        int parY = findParent(y);
        if(parX==parY) return;
        if(rank[parX]>=rank[parY]){
            rank[parX] += rank[parY];
            par[parY] = parX;
        }
        else{
            rank[parY] += rank[parX];
            par[parX] = parY;
        }
        cc--;
    }
    int getCC(){
        return cc;
    }
    void reset(){
        cc = sz;
        for(int i=0;i<=sz;i++){
            par[i] = i;
            rank[i] = 1;
        }
    }
    void print(){
        for(int i=0;i<=sz;i++){
            cout << i << "-> " << par[i] << " ";
        }
    }
};

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    int bst = -1, ben = -1;

    for(int i=0;i<n;i++){
        if(s[i]=='b'){
            if(bst==-1) bst = i;
            ben = i;
        }
    }

    int ans = 0;
    if(bst!=-1){
        int cntA = 0;
        for(int i=bst;i<=ben;i++){
            if(s[i]=='a') cntA++;
        }
        int aba = bst+(ben-bst+1 - cntA) + (n-ben-1);
        ans = max(ans,aba);

        int lb = 0;
        int cntB = n-cntA;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                int j = i;
                int cnt = 0;
                while(j<n && s[j]=='b'){
                    cnt++;
                    j++;
                }
                lb = max(cnt,lb);
            }
        }
        ans = max(ans,lb+cntA);
        ans = max(ans,cntA-cntB);
        ans = max(ans,cntB-cntA);
    }
    else ans = n;

    cout << ans << endl;
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
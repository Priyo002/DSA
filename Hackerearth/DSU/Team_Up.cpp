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

vector<int> team, par, strength, rankk;

int findParent(int x){
    if(par[x] == x) return x;
    return par[x] = findParent(par[x]);
}

void merge(int a,int b){
    int parA = findParent(a);
    int parB = findParent(b);
    if(parA == parB) return;
    if(rankk[parA] < rankk[parB]) swap(parA, parB);
    // rankk[parA] > rankk[parB]
    rankk[parA] += rankk[parB];
    strength[parA] += strength[parB];
    par[parB] = parA;
}

void solve(){
    int n, q;
    cin >> n >> q;

    team.resize(n+1);
    par.resize(n+1);
    strength.resize(n+1);
    rankk.assign(n+1,1);

    for(int i=0;i<=n;i++){
        team[i] = par[i] = strength[i] = i;
    }

    while(q--){
        int ch;
        cin >> ch;

        if(ch == 1){
            int a,b;
            cin >> a >> b;

            int teamA = team[a];
            int teamB = team[b];

            merge(teamA, teamB);
        }
        else if(ch == 2){
            int a;
            cin >> a;

            int teamA = team[a];
            int parA = findParent(teamA);
            cout << rankk[parA] << " " << strength[parA] << endl;
        }
        else{
            int a,b;
            cin >> a >> b;

            int parA = findParent(team[a]);
            int parB = findParent(team[b]);
 
            if(parA == parB) continue;
 
            team[a] = parB;
            rankk[parA]--;
            rankk[parB]++;
            strength[parA] -= a;
            strength[parB] += a;
        }
    }

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
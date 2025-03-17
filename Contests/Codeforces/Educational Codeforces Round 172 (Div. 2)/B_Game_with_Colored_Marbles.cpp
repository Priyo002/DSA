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


void solve(){
    int n;
    cin >> n;

    vector<int> arr(n), freq(n+1,0);

    for(int &x : arr){
        cin >> x;
        freq[x]++;
    }

    vector<int> alice(n+1,0), bob(n+1,0);
    vector<int> temp = freq;

    for(int i=0;i<n;i++){
        if(i&1){ // bob
            bool flag = false;
            for(int j=1;j<=n;j++){
                if(temp[j] && bob[j] == 0){
                    temp[j]--;
                    bob[j]++;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                bool f = false;
                for(int j=1;j<=n;j++){
                    if(temp[j] && alice[j] && bob[j] == 0){
                        temp[j]--;
                        bob[j]++;
                        f = true;
                        break;
                    }
                }
                if(!f){
                    int minIdx = -1;
                    for(int j=1;j<=n;j++){
                        if(temp[j]!=0){
                            if(minIdx == -1) minIdx = j;
                            else if(temp[j] < temp[minIdx]){
                                minIdx = j;
                            }
                        }
                    }
                    if(minIdx!=-1){
                        temp[minIdx]--;
                        bob[minIdx]++;
                    }
                }
            }
        }   
        else{ // alice
            bool flag = false;
            for(int j=1;j<=n;j++){
                if(temp[j] && alice[j] == 0){
                    temp[j]--;
                    alice[j]++;
                    flag = true;
                    break;
                }
            }

            if(!flag){
                int minIdx1 = -1, minIdx2 = -1;
                for(int j=1;j<=n;j++){
                    if(temp[j]!=0){
                        if(bob[j] == 0){
                            if(minIdx1 == -1) minIdx1 = j;
                            else if(temp[j] < temp[minIdx1]){
                                minIdx1 = j;
                            }
                        }
                        if(minIdx2 == -1) minIdx2 = j;
                        else if(temp[j] < temp[minIdx2]){
                            minIdx2 = j;
                        }
                    }
                }
                if(minIdx1!=-1){
                    temp[minIdx1]--;
                    alice[minIdx1]++;
                }
                if(minIdx2!=-1){
                    temp[minIdx2]--;
                    alice[minIdx2]++;
                }
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        if(alice[i]){
            ans++;
            if(freq[i] == alice[i]) ans++;
        }
    }

    cout << ans << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
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

int getScore(char &ch){
    if(tolower(ch) == 'q') return 9;
    if(tolower(ch) == 'r') return 5;
    if(tolower(ch) == 'b') return 3;
    if(tolower(ch) == 'n') return 3;
    if(tolower(ch) == 'p') return 1;
    return 0;
}

void solve(){
    vector<string> arr(8);
    for(int i=0;i<8;i++){
        cin >> arr[i];
    }

    int white = 0, black = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j] == '.') continue;
            if(isupper(arr[i][j])){
                white += getScore(arr[i][j]);
            }
            else{
                black += getScore(arr[i][j]);
            }
        }
    }
    if(white == black) cout << "Draw";
    else if(white > black) cout << "White";
    else cout << "Black";
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}
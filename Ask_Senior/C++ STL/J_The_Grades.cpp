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

#define pp pair<string,vector<int>> // {name, {totalMarks, A, M, S,E}}

void solve(){
    int n;
    cin >> n;

    vector<pp> arr(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        vector<int> marks(5);
        int sum = 0;
        for(int j=1;j<=4;j++){
            cin >> marks[j];
            sum += marks[j];
        }
        marks[0] = sum;
        arr[i] = {s,marks};
    }

    sort(arr.begin(),arr.end(),[](const pp &a, const pp &b){
        int sumA = a.second[0], sumB = b.second[0];
        if(sumA == sumB) return a.first < b.first;
        return sumA > sumB;
    });

    for(auto &x : arr){
        cout << x.first << " ";
        for(auto &y : x.second){
            cout << y << " ";
        }
        cout << endl;
    }

}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
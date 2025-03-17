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

const int MAX_CHAR = 26;


long double factorial(int n){
    long double fact = 1;
    for (int i = 2; i <= n; i++)
        fact = fact * i;
    return fact;
}
 

long double countDistinctPermutations(string& str){
    int length = str.length();
 
    int freq[MAX_CHAR];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < length; i++)
        if (str[i] >= 'a')
            freq[str[i] - 'a']++;
 

    long double fact = 1;
    for (int i = 0; i < MAX_CHAR; i++)
        fact = fact * factorial(freq[i]);

    return factorial(length) / fact;
}

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    long double mn = countDistinctPermutations(s);
    string ans = s;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string temp = s;
            temp[i] = temp[j];
            long double t = countDistinctPermutations(temp);
            if(t < mn){
                mn = t;
                ans = temp;
            }
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
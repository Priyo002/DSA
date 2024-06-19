#include <bits/stdc++.h>
#define int long long
using namespace std;



void solve(){
    int numElements;
    cin >> numElements;

    vector<int> elements(numElements);

    for(auto &element : elements) cin >> element;

    int lcm = 1;

    for(auto &element : elements){
        int gcd = __gcd(lcm, element);
        gcd = element / gcd;
        lcm *= gcd;
    }

    int sum = 0;
    vector<int> results;
    for(auto &element : elements){
        sum += lcm / element;
        results.push_back(lcm / element);
    }

    if(sum >= lcm){
        cout << -1 << endl;
    }
    else{
        for(auto &result : results){
            cout << result << " ";
        }
        cout << endl;
    }

    return;
}

signed main() {
    int _t;
    cin >> _t;
    while(_t--){
        solve();
    }
    return 0;
}

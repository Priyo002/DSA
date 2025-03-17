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
    int n, m;
	cin >> n >> m;
    
	if (m == 1) cout << 0 << endl;
	else if (n > m - 1) cout << m << endl;
	else cout << n + 1 << '\n';

	for (int i = 0; i < min(m - 1, n); i++) {
		for (int j = 0; j < m; j++) {
			cout << (j + i) % m << ' ';
		}
		cout << endl;
	}
	if (n > m - 1) {
		for (int i = m - 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << j << ' ';
			}
			cout << endl;
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
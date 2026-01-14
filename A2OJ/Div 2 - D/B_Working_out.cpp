#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;
const long long INF = 1e18;

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp1(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp2(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp3(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp4(n + 2, vector<int>(m + 2));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp1[i][j] = g[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);

    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            dp2[i][j] = g[i][j] + max(dp2[i + 1][j], dp2[i][j - 1]);

    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            dp3[i][j] = g[i][j] + max(dp3[i + 1][j], dp3[i][j + 1]);

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            dp4[i][j] = g[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);

    int ans = 0;

    for (int i = 2; i <= n - 1; i++) {
        for (int j = 2; j <= m - 1; j++) {
            int case1 = dp1[i - 1][j] + dp3[i + 1][j] + dp2[i][j - 1] + dp4[i][j + 1];
            int case2 = dp1[i][j - 1] + dp3[i][j + 1] + dp2[i + 1][j] + dp4[i - 1][j];
            ans = max(ans, max(case1, case2));
        }
    }

    cout << ans << endl;
}

int32_t main() {
    init();
    int _t = 1;
    // cin >> _t;
    while (_t--)
        solve();

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        // Try to match without insertion
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] >= b[j]) ++j;
            ++i;
        }
        if (j == m) {
            cout << 0 << '\n';
            continue;
        }

        // Now, try to find minimal k
        int ans = -1;
        // For each possible position to insert in b
        for (int ins = 0; ins < m; ++ins) {
            // Try to match b[0..ins-1] with a[0..]
            int i = 0, j = 0;
            while (i < n && j < ins) {
                if (a[i] >= b[j]) ++j;
                ++i;
            }
            if (j < ins) continue; // can't match first ins elements

            // Now, insert b[ins] as the new flower
            // Try to match b[ins+1..m-1] with a[i..]
            int ii = i, jj = ins + 1;
            while (ii < n && jj < m) {
                if (a[ii] >= b[jj]) ++jj;
                ++ii;
            }
            if (jj == m) {
                if (ans == -1 || ans > b[ins]) ans = b[ins];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
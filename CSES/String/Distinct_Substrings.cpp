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

// Function to compare two suffixes
bool compareSuffixes(int x, int y, int gap, const vector<int>& position, int n) {
    if (position[x] != position[y])
        return position[x] < position[y];
    x += gap;
    y += gap;
    return (x < n && y < n) ? position[x] < position[y] : x > y;
}

// Function to build the suffix array and return it
vector<int> buildSuffixArray(const string& s) {
    int n = s.size();
    vector<int> suffixArray(n), position(n), temporary(n);
    int gap = 0;

    // Initialize suffix array and position array
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
        position[i] = s[i];
    }

    // Iterate over gaps (powers of 2) for sorting
    for (gap = 1;; gap <<= 1) {
        // Sort suffix array using the current gap
        sort(suffixArray.begin(), suffixArray.end(),[&](int x, int y) { 
            return compareSuffixes(x, y, gap, position, n); 
        });

        // Update temporary array based on the sorted suffix array
        for (int i = 0; i < n - 1; i++) {
            temporary[i + 1] = temporary[i] + compareSuffixes(suffixArray[i], suffixArray[i + 1], gap, position, n);
        }

        // Update position array with temporary values
        for (int i = 0; i < n; i++) {
            position[suffixArray[i]] = temporary[i];
        }

        // Check if all suffixes are at their correct position
        if (temporary[n - 1] == n - 1) break;
    }

    return suffixArray;
}

// Function to build the LCP array and return it
vector<int> buildLCP(const string& s, const vector<int>& suffixArray) {
    int n = s.size();

    vector<int> position(n);
    for(int i=0;i<n;i++){
        position[suffixArray[i]] = i;
    }

    vector<int> LCP(n, 0);
    int k = 0;

    // Compute the LCP array
    for (int i = 0; i < n; i++) {
        if (position[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = suffixArray[position[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        LCP[position[i]] = k;
        if (k) k--;
    }

    return LCP;
}

void solve(){

    string s;
    cin >> s;
    
    int n = s.size();

    vector<int> suff = buildSuffixArray(s);
    vector<int> lcp = buildLCP(s,suff);

    int total = (n*(n+1))/2;
    int duplicate = accumulate(lcp.begin(),lcp.end(),0LL);

    cout << total - duplicate << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}
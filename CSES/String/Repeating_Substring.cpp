#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

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

// Main function
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Read the input string
    string s;
    cin >> s;
    int n = s.size();

    // Build the suffix array and LCP array
    vector<int> suffixArray = buildSuffixArray(s);
    vector<int> LCP = buildLCP(s, suffixArray);

    // Find the index of the maximum element in the LCP array
    int maxIndex = max_element(LCP.begin(), LCP.end()) - LCP.begin();

    // If the maximum LCP value is 0, no common substring exists
    if (LCP[maxIndex] == 0) {
        cout << -1 << endl;
        return 0;
    }

    // Output the longest common substring
    cout << s.substr(suffixArray[maxIndex], LCP[maxIndex]) << endl;
    return 0;
}

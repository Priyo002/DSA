#include <bits/stdc++.h>
using namespace std;
#define y1 as214
#define ll long long
#define int long long
#define MOD 998244353
const int MAXN = 1e6 + 5;

int testCases, arraySize;
int arrayValues[MAXN], maxValues[MAXN], minValues[MAXN], waysMax[MAXN], waysMin[MAXN];

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> testCases;

    while (testCases--) {
        cin >> arraySize;
        for (int i = 1; i <= arraySize; ++i) {
            cin >> arrayValues[i];
        }

        maxValues[1] = max(arrayValues[1], abs(arrayValues[1]));
        minValues[1] = min(arrayValues[1], abs(arrayValues[1]));

        if (arrayValues[1] >= 0) {
            waysMax[1] = 2;
            waysMin[1] = 2;
        } else {
            waysMax[1] = 1;
            waysMin[1] = 1;
        }

        for (int i = 2; i <= arraySize; ++i) {
            maxValues[i] = max({maxValues[i - 1] + arrayValues[i],
                                abs(maxValues[i - 1] + arrayValues[i]),
                                minValues[i - 1] + arrayValues[i],
                                abs(minValues[i - 1] + arrayValues[i])});

            if (maxValues[i] == maxValues[i - 1] + arrayValues[i])
                waysMax[i] = (waysMax[i] + waysMax[i - 1]) % MOD;

            if (maxValues[i] == abs(maxValues[i - 1] + arrayValues[i]))
                waysMax[i] = (waysMax[i] + waysMax[i - 1]) % MOD;

            if (maxValues[i - 1] != minValues[i - 1]) {
                if (maxValues[i] == minValues[i - 1] + arrayValues[i])
                    waysMax[i] = (waysMax[i] + waysMin[i - 1]) % MOD;

                if (maxValues[i] == abs(minValues[i - 1] + arrayValues[i]))
                    waysMax[i] = (waysMax[i] + waysMin[i - 1]) % MOD;
            }

            minValues[i] = min({maxValues[i - 1] + arrayValues[i],
                                abs(maxValues[i - 1] + arrayValues[i]),
                                minValues[i - 1] + arrayValues[i],
                                abs(minValues[i - 1] + arrayValues[i])});

            if (minValues[i] == maxValues[i - 1] + arrayValues[i])
                waysMin[i] = (waysMin[i] + waysMax[i - 1]) % MOD;

            if (minValues[i] == abs(maxValues[i - 1] + arrayValues[i]))
                waysMin[i] = (waysMin[i] + waysMax[i - 1]) % MOD;

            if (maxValues[i - 1] != minValues[i - 1]) {
                if (minValues[i] == minValues[i - 1] + arrayValues[i])
                    waysMin[i] = (waysMin[i] + waysMin[i - 1]) % MOD;

                if (minValues[i] == abs(minValues[i - 1] + arrayValues[i]))
                    waysMin[i] = (waysMin[i] + waysMin[i - 1]) % MOD;
            }
        }

        cout << waysMax[arraySize] << "\n";
        for (int i = 1; i <= arraySize; ++i) {
            waysMax[i] = waysMin[i] = 0;
        }
    }
}

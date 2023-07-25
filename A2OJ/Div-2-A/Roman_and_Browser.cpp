#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int N, K;
	cin >> N >> K;
	vector<int> tabs(N);

	for (int i = 0; i < N; i++)
		cin >> tabs[i];

	int most = 0;

	for (int b = 0; b < N; b++) {
		int sum = 0;

		for (int i = 0; i < N; i++)
			if (i % K != b % K)
				sum += tabs[i];

		most = max(most, abs(sum));
	}

	cout << most << '\n';
}
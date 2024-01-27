#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const long long INF = 1e18;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void f(string input, string output) {
	if (input.size() == 0) {
		cout << output << endl;
		return;
	}
	for (int i = 0; i < input.size(); i++) {
		char ch = input[i];
		string left = input.substr(0, i);
		string right = input.substr(i + 1);
		string rest = left + right;
		f(rest, output + ch);
	}
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	string str = "abc";
	f(str, "");

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define vi for(int i=0;i<n;i++)

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	set<int> s;
	s.insert(3);//O(logn)
	s.insert(8);
	s.insert(-1);
	for (auto i : s) cout << i << " ";
	cout << endl;

	map<string, int> m;
	m["hello"] = 1;
	m["aee"] = 3;
	m["bee"] = 5;
	for (auto i : m)
		cout << i.first << " " << i.second << endl;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	pair<string, int> p;
	p.first = "Priyo";
	p.second = 6;
	cout << p.first << p.second << endl;
	unordered_map<string, int> m;
	m.insert(p);
	m.insert(make_pair("hello", 9));
	m.insert(make_pair("hell", 10));
	m["hi"] = 28;
	m["Nooo"] = 9;
	m.erase("hi");
	for (auto it : m) {
		cout << it.first << it.second << endl;
	}

}
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string s;
	getline(cin, s);
	stringstream ss(s);
	string temp, str = "";
	while (ss >> temp) {
		reverse(temp.begin(), temp.end());
		str += temp;
		str += " ";
	}
	int i = str.size() - 1;
	str.erase(str.begin() + i);
	cout << str;
}
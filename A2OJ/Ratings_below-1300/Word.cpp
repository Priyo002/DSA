#include<bits/stdc++.h>
using namespace std;

void convertUp(string str) {
	string ans = "";
	for (int i = 0; i < str.size(); i++) {
		if (isupper(str[i])) {
			ans += str[i];
		}
		else ans += (str[i] - 32);
	}
	cout << ans;
}
void convertLow(string str) {
	string ans = "";
	for (int i = 0; i < str.size(); i++) {
		if (islower(str[i])) {
			ans += str[i];
		}
		else ans += (str[i] + 32);
	}
	cout << ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string str;
	cin >> str;
	int up = 0, low = 0;
	int n = str.size();
	for (int i = 0; i < n; i++) {
		if (islower(str[i])) low++;
		else up++;
	}
	if (up > low) {
		convertUp(str);
	}
	else convertLow(str);

}
#include<bits/stdc++.h>
using namespace std;

// void removeChar(string ans, string original) {
// 	if (original.size() == 0) {
// 		cout << ans;
// 		return;
// 	}
// 	char ch = original[0];
// 	if (ch == 'a') {
// 		removeChar(ans, original.substr(1));
// 	}
// 	else removeChar(ans + ch, original.substr(1));
// }

void removeChar(string ans, string original, int idx) {
	if (original.size() == idx) {
		cout << ans;
		return;
	}
	char ch = original[idx];
	if (ch == 'a') {
		removeChar(ans, original, idx + 1);
	}
	else removeChar(ans + ch, original, idx + 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	string str = "Hallo";
	removeChar("", str, 0);

}
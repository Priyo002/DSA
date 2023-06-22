#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	long long n;
	cin >> n;
	int years = n / 365;
	if (years)
		n = n % 365;
	int months = n / 30;
	if (months)
		n = n % 30;
	int days = n;

	cout << years << " years" << endl;
	cout << months << " months" << endl;
	cout << days << " days";

}
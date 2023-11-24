#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

// int powr(int a, int b) {
// 	int res = 1;
// 	while (b) {
// 		if (b & 1) res *= a;
// 		a *= a;
// 		b = (b >> 1);
// 	}
// 	return res;
// }

vector<ll> v(18, 0);

void cal(vector<ll> &v)
{
	for (ll i = 1; i <= 17; i++)
	{
		v[i] = ((9 * i * pow(10, i - 1)));
	}
	return;
}

ll solve()
{
	cal(v);

	// printing value of v
	// for(auto i:v)
	// {
	//     cout<<i<<" ";
	// }
	// cout<<endl;


	ll query = 1;
	cin >> query;
	while (query--)
	{
		ll k;
		cin >> k;

		ll sum = 0;
		ll length_of_number = 0;
		for (ll i = 0; i <= 17; i++)
		{
			sum += v[i];
			if (sum <= k)
			{
				length_of_number = i + 1;
			}
			else
			{
				break;
			}
		}


		sum -= v[length_of_number];
		// cout<<"sum : "<<sum<<endl;
		ll difference = k - sum;
		// cout<<"difference : "<<difference<<endl;
		ll starting_number = pow(10, length_of_number - 1);
		ll distance_from_starting_number = (difference / length_of_number);
		// sum += (distance_from_starting_number * length_of_number);
		ll actual_number = starting_number + distance_from_starting_number - 1;
		ll remainder = difference % length_of_number;
		// cout<<"remainder : "<<remainder<<endl;
		// cout<<"actual_number : "<<actual_number<<endl;
		// cout<<"sum : "<<sum<<endl;
		if (remainder == 0)
		{
			cout << actual_number % 10 << endl;
		}
		else
		{
			actual_number++;
			// cout<<"final actual number : "<<actual_number<<endl;
			remainder = length_of_number - remainder;
			while (remainder--)
			{
				actual_number /= 10;
			}
			cout << actual_number % 10 << endl;
		}
	}

	return 0;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();
	solve();
	// vector<int> digits(19, 0);
	// make(digits);
	// int t;
	// cin >> t;
	// while (t--)
	// 	solve(digits);

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}
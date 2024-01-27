#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int mod = 1e9 + 7;

void init() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

class Product {
public:
	int price;
	string name;
	Product(int p, string n) {
		this->price = p;
		this->name = n;
	}
};

bool cmp(const Product& p1, const Product& p2) {
	if (p1.price == p2.price) {
		return p1.name < p2.name;
	}
	return p1.price < p2.price;
}

int main() {

	init();

	vector<Product> v;
	Product p1(100, "abc");
	Product p2(45, "def");
	Product p3(10, "ghi");
	Product p4(10, "bc");
	Product p5(10, "ac");

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].price << "->" << v[i].name << endl;
	}

}
#include<bits/stdc++.h>
using namespace std;

class Book {

public:
	string name;
	int price;
	int noOfpages;

	int countbooks(int p) {
		if (price < p) return 1;
		else return 0;
	}

	bool isbookPresent(string book) {
		if (name == book) return true;
		else return false;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Book math;
	math.name = "R D Sharma";
	math.price = 1000;
	math.noOfpages = 900;

	cout << math.isbookPresent("R D Sharma");


}
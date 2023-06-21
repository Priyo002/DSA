#include <iostream>
using namespace std;

int main() {
	long long A, B, C, D, X, S, Y;
	cin >> A >> B >> C >> D ;
	A %= 100;
	B %= 100;
	C %= 100;
	D %= 100;

	X = A * B;
	S = C * D;
	X %= 100;
	S %= 100;


	Y = (X * S) % 100;
	if (Y < 10)
		cout << 0 << Y ;
	else
		cout << Y ;

	return 0;
}
#include<bits/stdc++.h>
using namespace std;

//Access Modifier : public,private,protected;

class Player {
private:
	//Data Members
	int score;
	int health;
	string name;

public:
	//Member Function
	void showHealth() {
		cout << "Health is " << health;
	}

	//Setter
	void setScore(int s) {
		score = s;
	}
	void setHealth(int h) {
		health = h;
	}

	//Getter
	int getScore() {
		return score;
	}
	int getHealth() {
		return health;
	}
};

class Calculator {
public:
	int a;
	int b;

	void add() {
		cout << a + b;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Player Priyo;
	Priyo.setScore(100);
	Priyo.setHealth(60);

	cout << Priyo.getScore() << endl;
	cout << Priyo.getHealth() << endl;
	cout << endl;

	// Calculator calcii;
	// calcii.a = 10;
	// calcii.b = 19;
	// calcii.add();

}
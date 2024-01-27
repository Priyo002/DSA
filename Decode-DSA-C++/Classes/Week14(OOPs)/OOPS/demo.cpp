#include<bits/stdc++.h>
using namespace std;

class player {
private:
	int health;
	int age;
	int score;
	bool alive;
public:
	int getHealth() {
		return health;
	}
	int getAge() {
		return age;
	}
	int getScore() {
		return score;
	}
	bool isAlive() {
		return alive;
	}

	void setHealth(int health) {
		this->health = health;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setScore(int score) {
		this->score = score;
	}
	void setIsAlive(bool alive) {
		this->alive = alive;
	}
};

int addScore(player a, player b) {
	return a.getScore() + b.getScore();
}

player getMaxScore(player a, player b) {
	if (a.getScore() > b.getScore()) return a;
	else return b;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	//Static Allocation
	player amit;
	player ayan;

	//Dynamic Allocation(Run time)
	player *troyee = new player;
	player shree = *troyee;

	amit.setAge(19);
	amit.setScore(199);
	amit.setHealth(80);
	amit.setIsAlive(true);

	ayan.setAge(18);
	ayan.setScore(90);
	ayan.setHealth(100);
	ayan.setIsAlive(true);

	(*troyee).setAge(19);
	cout << (*troyee).getAge() << endl;

	troyee->setHealth(1000);
	cout << troyee->getHealth() << endl;

	shree.setScore(90);
	cout << shree.getScore() << endl;

	cout << addScore(amit, ayan) << endl;
	player ankita = getMaxScore(amit, ayan);//amit
	cout << ankita.getScore() << endl;

	//Dynamic Memory allocation
	int *a;
	a = new int (5);
	cout << *a;

}
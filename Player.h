#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>

using namespace std;

class Player {
private:
	int userChoice = 0;

public:
	string name;
	vector<Card> cards;

	Player();
	Card play(Card curr);
	void inputPlayerName(int num);
	void printGameStat(Card current) const;
	Card inputPlayerChoice(int *userChoice, Card current);
};
#endif




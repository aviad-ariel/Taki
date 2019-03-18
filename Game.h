#ifndef GAME_H
#define GAME_H

#include <queue>
#include "Player.h"
#include "Card.h"
class Game {
private:
	bool stillPlaying = true;
	int numOfPlayres = 0;
	int howManyCards = 0;
	static queue<Player> players;
	static Card currCard;

	void initPlayers(int numOfPlayres, int howManyCards);
	void cardDealer(int howManyCards, Player* player) const;
	void inputGameParameter();
	void reverseQueue(queue<Player>& Queue) const;
	void nextTurn(int howMany);
	void nextTurn();
	bool isWinner(Player player) const;
	int turnHandler(Card card) const;
public:
	Game();
	void start();

};
#endif





#include "Game.h"
#include <stdio.h>
#include <queue>
#include <stack>
#include "Player.h"
#include "Card.h"

using namespace std;

Card Game::currCard = Game::currCard.generate_card();
queue<Player> Game::players = queue<Player>();

Game::Game() {
    inputGameParameter();
    initPlayers(numOfPlayres, howManyCards);
}

void Game::start() {
    while (stillPlaying) {
        Card userCardChoice = players.front().play(currCard);
        if (userCardChoice.get_sign() == sign::NAS) {
            nextTurn();
            continue;
        }
        Game::currCard = userCardChoice;
        if(isWinner(players.front())){
            cout << players.front().name;
            cout << " wins!";
            break;
        }
        nextTurn(turnHandler(userCardChoice));
    }
}

void Game::inputGameParameter() {
    cout << "How many players?";
    cin >> Game::numOfPlayres;

    cout << "How many cards";
    cin >> Game::howManyCards;
}

void Game::initPlayers(int numOfPlayres, int howManyCards) {
    for (int i = 1; i <= numOfPlayres; i++) {
        Player player = Player();
        player.inputPlayerName(i);
        cardDealer(howManyCards, &player);
        Game::players.push(player);
    }

}

void Game::cardDealer(int howManyCards, Player *player) const{
    for (int i = 0; i < howManyCards; i++) {
        Card tmp = Card::generate_card();
        player->cards.push_back(tmp);
    }
}

void Game::reverseQueue(queue<Player> &Queue) const{
    stack<Player> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}

void Game::nextTurn(int howMany) {
    for (int i = 0; i < howMany; i++) {
        Player tmp;
        tmp = players.front();
        players.pop();
        players.push(tmp);
    }
}

void Game::nextTurn() {
        Player tmp;
        tmp = players.front();
        players.pop();
        players.push(tmp);
}

bool Game::isWinner(Player player) const{
    return player.cards.empty();
}

int Game::turnHandler(Card card) const{
    switch (card.get_sign()){
        case sign::PLUS:
            return 0;
        case sign::CD:
            reverseQueue(players);
            return 0;
        case sign::STOP:
            return 2;
        default:
            return 1;
    }
}

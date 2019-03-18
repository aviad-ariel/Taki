#include "Player.h"

Card Player::play(Card curr) {
    this->printGameStat(curr);

    Card userCardChoice = this->inputPlayerChoice(&userChoice, curr);
    if (userCardChoice.get_sign() != sign::NAS) {
        this->cards.erase(this->cards.begin() + userChoice - 1);
        curr = userCardChoice;
    } else {
        Card newCard = newCard.generate_card();
        this->cards.push_back(newCard);
        curr = Card(color::NAC,sign::NAS);
    }
    return curr;
}

void Player::inputPlayerName(int num) {
    cout << "Player number " + to_string(num) + " name?";
    cin >> this->name;
}

void Player::printGameStat (Card current) const{
    int i = 1;
    cout << "Current:";
    cout << current;
    cout << "\n" + this->name + ", your turn -\n";
    cout << "Your cards:";
    for (Card card : this->cards) {
        cout << "(" + to_string(i) + ")";
        cout << card;
        cout << " ";
        i++;
    }
}

Card Player::inputPlayerChoice(int *userChoice, Card current) {
    Card choice;
    do{
        cout << "\n";
        cin >> *userChoice;
        if(*userChoice <= this->cards.size() && *userChoice > 0){
            choice = this->cards.at(*userChoice-1);

            if (choice.get_color() == current.get_color() ||
                choice.get_sign() == current.get_sign()) {

                return choice;
            }
            else {
                cout << "you can't put ";
                cout << this->cards.at(*userChoice - 1);
                cout << " on ";
                cout << current;
                cout << '\n';
            }
        } else{
            choice = Card(color::NAC, sign::NAS);
            return choice;
        }
    }while(true);
}

Player::Player() {
    this->name = "NAN";
    this->cards = vector<Card>();
}

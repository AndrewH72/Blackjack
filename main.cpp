#include "deck.h"
#include <iostream>

int main(){
    Deck theDeck;
    theDeck.createDeck();

    for(int i = 0; i < 52; i++){
        Card topCard = theDeck.top();
        theDeck.pop();
        cout << topCard.getSuit() << " " << topCard.getValue() << endl;
    }
}
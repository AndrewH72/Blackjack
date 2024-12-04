#ifndef DECK_H
#define DECK_H
#include <random>
#include <time.h>
#include "card.h"

class Deck{
   private:
    static const int deckSize = 52;
    static const int numSuits = 4;
    string suitTypes[numSuits] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    Card deckQueue[deckSize];
    int topCard;
    int numCards;
   public:
    Deck();

    bool push(Card);
    bool pop();
    Card top();
    bool isEmpty();
    bool isFull();

    void swapCards(Card&, Card&);
    void shuffleDeck();
    void createDeck();
};

#endif
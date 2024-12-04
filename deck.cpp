#include "deck.h"
Deck::Deck(){
    topCard = 0;
    numCards = 0;
}

bool Deck::push(Card cardToPush){
    if(!isFull()){
        deckQueue[numCards] = cardToPush;
        numCards++;
    }
    return isFull();
}

bool Deck::pop(){
    if(!isEmpty()){
        topCard++;
    }
    return isEmpty();
}

Card Deck::top(){
    return deckQueue[topCard];
}

bool Deck::isEmpty(){
    return (numCards <= 0);
}

bool Deck::isFull(){
    return (numCards > 52);
}

void Deck::swapCards(Card& cardOne, Card& cardTwo){
    Card temp = Card(cardOne);
    cardOne = Card(cardTwo);
    cardTwo = Card(temp);
}

void Deck::shuffleDeck(){
    srand(time(NULL));

    for(int i = numCards - 1; i > 0; i--){
        int j = rand() % (i + 1);
        swapCards(deckQueue[i], deckQueue[j]);
    }
}

void Deck::createDeck(){
    for(int i = 0; i < numSuits; i++){
        for(int j = 1; j < deckSize / numSuits + 1; j++){
            if(!isFull()){
                Card cardToPush = Card(j, suitTypes[i]);
                push(cardToPush);
            }
        }
    }
    shuffleDeck();
}
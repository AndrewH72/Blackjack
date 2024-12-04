#include "deck.h"
#include <iostream>

void blackJackGame(Deck&);
string convertCards(int);
void dealHands(Deck&, Deck&, Deck&, int&, int&);

int main(){
    Deck theDeck;
    theDeck.createDeck();

    blackJackGame(theDeck);
}


void blackJackGame(Deck& actualDeck){
    Deck playerHand, opponentHand;
    int playerPoints, opponentPoints;

    dealHands(actualDeck, playerHand, opponentHand, playerPoints, opponentPoints);
}

string convertCards(int cardValue){
    switch(cardValue){
        case 1:
            return "Ace";
            break;
        case 2:
            return "2";
            break;
        case 3:
            return "3";
            break;
        case 4:
            return "4";
            break;
        case 5:
            return "5";
            break;
        case 6:
            return "6";
            break;
        case 7:
            return "7";
            break;
        case 8:
            return "8";
            break;
        case 9:
            return "9";
            break;
        case 10:
            return "10";
            break;
        case 11:
            return "Jack";
            break;
        case 12:
            return "Queen";
            break;
        case 13:
            return "King";
            break;
        default:
            return "NA";
    }
}
void dealHands(Deck& aDeck, Deck& pHand, Deck& oHand, int& pPoints, int& oPoints){
    for(int i = 0; i < 4; i++){
        Card cardToDeal = aDeck.top();
        aDeck.pop();

        if(i % 2 == 0){
            pHand.push(cardToDeal);
            cout << "You have a/an: " << convertCards(cardToDeal.getValue()) << " of " << cardToDeal.getSuit() << endl;
            pPoints += cardToDeal.getValue();
        }
        else{
            oHand.push(cardToDeal);
        }
    }
    cout << "You current have " << pPoints << " points." << endl;
    cout << "\nThe opponent has a/an: " << convertCards(oHand.top().getValue()) << " of " << oHand.top().getSuit() << endl;

    oPoints += oHand.top().getValue();
    cout << "Your opponent is showing " << oPoints << " points." << endl;
}
#include "deck.h"
#include <iostream>

void blackJackGame(Deck&);
string convertCards(int);
void dealHands(Deck&, Deck&, Deck&, int&, int&, Card&);

int main(){
    Deck theDeck;
    theDeck.createDeck();

    blackJackGame(theDeck);
}


void blackJackGame(Deck& actualDeck){
    Deck playerHand, opponentHand;
    Card hiddenCard;
    int playerPoints = 0, opponentPoints = 0;
    string hitOrPass;

    dealHands(actualDeck, playerHand, opponentHand, playerPoints, opponentPoints, hiddenCard);
    do{
        cout << "\nDo you want to hit (get another card) or pass? (Y/N): ";
        cin >> hitOrPass;
        cout << endl;

        if(hitOrPass == "Y" || hitOrPass == "y"){
            Card cardToDeal = actualDeck.top();
            actualDeck.pop();
            playerHand.push(cardToDeal);

            playerPoints += cardToDeal.getValue();
            cout << "\nYou got a/an: " << convertCards(cardToDeal.getValue()) << " of " << cardToDeal.getSuit() << endl;
            cout << "You now have " << playerPoints << " points." << endl;
        }
    }while((hitOrPass != "N" && hitOrPass != "n") && (playerPoints <= 21 && opponentPoints <= 21));

    cout << "Your opponent was hiding a: " << convertCards(hiddenCard.getValue()) << " of " << hiddenCard.getSuit() << endl;
    do{
        Card cardToDeal = actualDeck.top();
        actualDeck.pop();
        opponentHand.push(cardToDeal);
        opponentPoints += cardToDeal.getValue();

        cout << "Your opponent got a: " << convertCards(cardToDeal.getValue()) << " of " << cardToDeal.getSuit() << endl;
        cout << "They now have " << opponentPoints << " points." << endl;
    }while(opponentPoints < 17);
    
    if(playerPoints > 21){
        cout << "\nYou went over 21. YOU LOSE!" << endl;
    }
    else if(opponentPoints > 21){
        cout << "\nYour opponent went over 21. THEY LOSE!" << endl;
    }
    else if(playerPoints > opponentPoints){
        cout << "\nYOU WON!" << endl;
    }
    else{
        cout << "\nYOUR OPPONENT WON!" << endl;
    }
}
string convertCards(int cardValue){
    string tenValueCards[4] = {"10", "Jack", "Queen", "King"};
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
            {
                int randomNumber = rand() % 4;
                return tenValueCards[randomNumber];
                break;
            }
        default:
            return "NA";
    }
}
void dealHands(Deck& aDeck, Deck& pHand, Deck& oHand, int& pPoints, int& oPoints, Card& hCard){
    cout << "The goal of the game is to get more points than your opponent, however, you can only go up to 21 points. If you have more than 21 points, you instantly lose.\n" << endl;
    for(int i = 0; i < 4; i++){
        Card cardToDeal = aDeck.top();
        aDeck.pop();

        if(i % 2 == 0){
            pHand.push(cardToDeal);
            cout << "You have a/an: " << convertCards(cardToDeal.getValue()) << " of " << cardToDeal.getSuit() << endl;
            pPoints += cardToDeal.getValue();
        }
        else{
            if(i == 1){
                hCard = cardToDeal;
            }
            oHand.push(cardToDeal);
            oPoints += cardToDeal.getValue();
        }
    }
    cout << "You current have " << pPoints << " points." << endl;
    cout << "\nThe opponent has a/an: " << convertCards(oHand.top().getValue()) << " of " << oHand.top().getSuit() << endl;

    cout << "Your opponent is showing " << oHand.top().getValue() << " points." << endl;
}
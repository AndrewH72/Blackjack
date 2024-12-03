#include "card.h"

Card::Card(){
    value = 0;
    suit = "NA";
}

Card::Card(int v, string s){
    value = v;
    suit = s;
}

Card::Card(const Card& other){
    value = other.value;
    suit = other.suit;
}

int Card::getValue(){
    return value;
}

void Card::setValue(int v){
    value = v;
}

string Card::getSuit(){
    return suit;
}

void Card::setSuit(string s){
    suit = s;
}

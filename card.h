#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card{
    private:
        int value;
        string suit;
    public:
        Card();
        Card(int, string);
        Card(const Card&);

        int getValue();
        void setValue(int);
        string getSuit();
        void setSuit(string);
};

#endif
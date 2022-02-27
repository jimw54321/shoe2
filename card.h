#ifndef CARD_H
#define CARD_H

// trivial class to hold the value and suit of a card.
class Card
{
    char suit;
    char value;
public:
    Card(char v, char s) : value(v), suit(s) {}
    char getvalue() const { return value; }
    char getsuit() const { return suit; }
};

#endif

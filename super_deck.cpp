
#include <vector>
#include <list>
#include <stack>
#include "card.h"
#include "super_deck.h"
#include "random_ints.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void create_super_deck(int ndecks, std::vector<Card> & super_deck)
{
    std::list<char> suits = { 'c', 's', 'h', 'd' };
    std::list<char> values = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

    // create a super-deck of cards (ndecks is the number of decks).
    for (int i = 0; i < ndecks; ++i)
    {
        for (auto suit : suits)
        {
            for (auto value : values)
            {
                Card card(value, suit);
                super_deck.push_back(card);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// pick random cards from the super-deck to add to the shoe.  seems like might be terribly
// inefficient, but better way using STL escapes me for now.
void get_cards_from_super_deck(std::stack<Card>& shoe, std::vector<Card>& super_deck)
{
    while (!super_deck.empty())
    {
        int n = random_num(super_deck.size());
        Card card = super_deck[n];
        shoe.push(card);
        super_deck.erase(super_deck.begin() + n);
    }
}

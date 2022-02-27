// Simulates the filling of a shoe of cards.  The number of decks to fill the shoe is added by the user.
// This is the final assignment from Bill Weinman's course on LinkedIn "C++ Essential Training".

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <stack>
#include "card.h"
#include "random_ints.h"
#include "super_deck.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// specify how to print a card.
std::ostream& operator << (std::ostream& stream, const Card& card)
{
    stream << card.getvalue() << card.getsuit();
    return stream;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_num_decks()
{
    std::cout << "how many decks in the shoe? ";
    int ndecks = 0;
    std::cin >> ndecks;

    return ndecks;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display_shoe(std::stack<Card>& shoe)
{
    // prove that we have random ordered cards.  replaced for loop with while in case we did
    // not correctly fill the shoe.
    // for (int i = 0; i < 52 * ndecks; ++i)
    while (!shoe.empty())
    {
        Card card = shoe.top();
        std::cout << card << std::endl;
        shoe.pop();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    seed_rand_func();

    std::vector<Card> super_deck;
    std::stack<Card> shoe;

    int ndecks = get_num_decks();
    create_super_deck(ndecks, super_deck);

    get_cards_from_super_deck(shoe, super_deck);

    display_shoe(shoe);

    return 0;
}


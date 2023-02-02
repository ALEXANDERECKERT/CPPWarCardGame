#pragma once
#include <vector>
#include "Card.h"
#include "deck.h"
class War
{
public:
    War();
    ~War();
    void newGame();
    void playGame();
    

    


protected:
    Card* A;
    Card* B;
    deck P1Deck;
    deck P2Deck;
    deck P3Deck;
};

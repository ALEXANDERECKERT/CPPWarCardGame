#include <stdlib.h>
#include "Card.h"
#include <iostream>
Card::Card(int CardNum, int CardType)
{
    this->CN = CardNum;
    this->CT = CardType;
}
Card::~Card()
{
}
int Card::returnSuit()
{
    return this->CT;
}
int Card::returnCN()
{
    return this->CN;
}
// return of 0 indicates this card is less than the other, 1 indicates equality, 2 indicates this card is larger
int Card::CompareThisCardSuitAgainst(Card C) {
    this->print();
    int x = 99;
    if (this->CT == C.returnSuit()) {
        std::cout << " shares a suit type with ";


        x = 1;
    }
    else {
        std::cout << " does NOT share a suit type with ";


        x = 0;
    }
    C.print();
    return x;


}
int Card::CompareThisCardNumAgainst(Card C) {
    this->print();
    int x = 99;
    if (this->CN < C.returnCN()) {
        
        std::cout << " is less than ";
        

        x = 0;
    }
    else if (this->CN == C.returnCN()) {
        std::cout << " is equal to ";
        x = 1;
    }
    else if (this->CN > C.returnCN()) {
        std::cout << " is greater than ";
        x = 2;
    }
    C.print();
    return x;
   
}
void Card::print() {
    if (this->CN <= 10) {
        std::cout << this->CN;
    }
    else if (this->CN <= 11) {
        std::cout << "Jack";
    }
    else if (this->CN <= 12) {
        std::cout << "Queen";
    }
    else if (this->CN <= 13) {
        std::cout << "King";
    }
    else if (this->CN <= 14) {
        std::cout << "Ace";
    }
    if (this->CT == 1) {
        std::cout << " of Hearts \n";
    }
    else if (this->CT == 2) {
        std::cout << " of Diamonds \n";
    }
    else if(this->CT == 3) {
        std::cout << " of Clubs \n";
    }
    else if (this->CT == 4) {
        std::cout << " of Spades \n";
    }
}
#pragma once
class Card
{
public:
    Card(int CardNum, int CardType);
    ~Card();
public:
    int returnSuit();
    int returnCN();
    void print();
    // return of 0 indicates this card is less than the other, 1 indicates equality, 2 indicates this card is larger
    int CompareThisCardNumAgainst(Card C);
    // return of 0 indicates Equivalency, 1 indicates equality, 2 indicates non-equivalency
    int CompareThisCardSuitAgainst(Card C);
    
    
protected:
    int CN;
    int CT;
    
};

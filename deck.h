#pragma once
#include <vector>
#include "Card.h"
#include "deck.h"
class deck
{
public:
    deck();
    ~deck();
    void shuffle();
    void printDeck();
    int getSize();
    void clearDeck();
    void addExistingCards();
    void addToDeck(Card* C);
    void addToBackDeck(Card* C);
    void addToDeck(deck D);
    void addToDeck(Card* C, Card* B);
    void buildDeck();
    void printCard(Card* C);
    Card* newCard(int& N,int& S);
   
    Card* drawCard();
public:
  //  int DealCard();
    
  //  void print();
    


protected:
   
    std::vector<Card*> Deck;
    std::vector<Card*> Deck2;
};
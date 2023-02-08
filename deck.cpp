#include <stdlib.h>
#include "deck.h"
#include "Card.h"
#include <iostream>
#include <time.h>
#include <random>

deck::deck()
{
    buildDeck();
}
void deck::buildDeck() {
    this->Deck.clear();    
    this->Deck2.clear();
    for (int x = 1; x < 5; x++) {
        for (int z = 1; z < 14; z++) {
            Card* CardA = new Card(z, x);
            this->Deck.push_back(CardA);
        }
    }
}
void deck::clearDeck() {
    this->Deck2.clear();
    this->Deck.clear();
}
void deck::addToDeck(Card* CardA) {
    this->Deck2.clear();
    this->Deck2.push_back(CardA);
    addExistingCards();
    this->Deck2.clear();

}
void deck::addToDeck(Card* CardA, Card* B) {
    this->Deck2.clear();
    this->Deck2.push_back(CardA);
    this->Deck2.push_back(B);
    addExistingCards();
    this->Deck2.clear();

}
void deck::addToDeck(deck D) {
    this->Deck2.clear();
    D.printDeck();
    for (int g = 0; g < D.getSize(); g++) {
        std::cout << "X";
        Card* N = new Card(D.Deck[g]->returnCN(), D.Deck[g]->returnSuit());
        this->Deck2.push_back(N);
    }


}
int deck::getSize() {
    return this->Deck.size();
}
void deck::addExistingCards() {
    for (int x = 0; x < this->Deck.size(); x++) {

        this->Deck2.push_back(this->Deck[x]);
    }
    this->Deck.clear();
    for (int x = 0; x < this->Deck2.size(); x++) {
        this->Deck.push_back(this->Deck2[x]);
    }
}

void deck::shuffle()
{
    int x = 0;
    
    int N = 0;
    int S = 0;
    std::cout << "\r\n Shuffling... \r\n";
    Card* CardA = newCard(N, S);
    std::random_device rd;
    Card* CardC = new Card(99,99);
    srand(rd());
    x = rand() % this->Deck.size();
    for (int y = 0; y < 300; y++) {
        
        x = rand() % this->Deck.size();
        
        if (Deck[x]->returnCN() == 99) {}
        else {
            N = this->Deck[x]->returnCN();
            S = this->Deck[x]->returnSuit();
            CardA = newCard(N, S);
            this->Deck2.push_back(CardA);           
            this->Deck[x] = CardC;
           
                    }
       

    }
    for (int y = (this->Deck.size() - 1); y >= 0; y--) {
        if (Deck[y]->returnCN() == 99) {}
        else {
            N = this->Deck[y]->returnCN();
            S = this->Deck[y]->returnSuit();
            CardA = newCard(N, S);
            this->Deck2.push_back(CardA);
            this->Deck[y] = CardC;


        }
    }
    this->Deck.clear();
    this->Deck = this->Deck2;
    this->Deck2.clear();
}


Card* deck::newCard(int& N, int& S) {
    Card* CardA = new Card(N,S);
    return CardA;
}
Card* deck::drawCard() {
    
    
    int a = this->Deck[this->Deck.size() - 1]->returnSuit();
    int b = this->Deck[this->Deck.size() - 1]->returnCN();
    Card* C = newCard(b,a);
    this->Deck.pop_back();
    return C;
}
void deck::addToBackDeck(Card* C) {
    this->Deck2.push_back(C);
}
void deck::printCard(Card* C) {
    

    if (C->returnCN() == 1) {
        std::cout << "Ace ";
    }
    else if (C->returnCN() == 11) {
        std::cout << "Jack ";
    }
    else if (C->returnCN() == 12) {
        std::cout << "Queen ";
    }
    else if (C->returnCN() == 13) {
        std::cout << "King ";
    }
    else {
        std::cout << C->returnCN() << " ";
    }
    if (C->returnSuit() == 1) {
        std::cout << "of Hearts" << "\r\n";
    }
    if (C->returnSuit() == 2) {
        std::cout << "of Diamonds" << "\r\n";
    }
    if (C->returnSuit() == 3) {
        std::cout << "of Clubs" << "\r\n";
    }
    if (C->returnSuit() == 4) {
        std::cout << "of Spades" << "\r\n";
    }
}
void deck::printDeck() {
    int UpperBound = this->Deck.size();
    std::cout  << "             The deck currently holds:           \r\n";
    for (int i = 0; i < UpperBound; i++) {
        std::cout << i << ".)";            
        this->printCard(Deck[i]);          
        
    }
    std::cout << "\r\n";
    std::cout << "\r\n";
}
deck::~deck()
{
    for (int x = 0; x < this->Deck.size(); x++) {
        delete this->Deck[x];
    }
    for (int x = 0; x < this->Deck2.size(); x++) {
        delete this->Deck2[x];
    }
}

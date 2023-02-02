#include <stdlib.h>
#include "War.h"
#include "deck.h"
#include "Card.h"
#include <iostream>
#include <time.h>
#include <random>
War::War()
{
    newGame();
}
void War::newGame()
{
 
    P1Deck.shuffle();
    P2Deck.clearDeck();

    for (int x = 0; x < 26; x++) {

        P2Deck.addToDeck(P1Deck.drawCard());
    }
    P1Deck.printDeck();
    P2Deck.printDeck();
}
void War::playGame() {
    
    
    int x = 99;
    
    while (x > 0) {
        std::cout << "Press 1 for another round, 2 to shuffle, 3 to display both decks, and 0 to forfeit";
        std::cin >> x;
        if (x == 3) {
            P1Deck.printDeck();
            P2Deck.printDeck();
        }
        if (x == 2) {
            P1Deck.shuffle();
            P2Deck.shuffle();
        }
        if (x == 0) {
            
            std::cout << "Game over... Player 1 score: " << P1Deck.getSize() << "AI score: " << P2Deck.getSize();
        }
        if (x == 1) {
            Card* A = new Card(10,2);
            Card* B = new Card(3, 3);
            
            
            B= P2Deck.drawCard();
            A = P1Deck.drawCard(); 
            
            

            std::cout << "Player 1 Wields:";
            A->print();
            std::cout << "Player 2 Wields:";
            B->print();
            int T1 = A->returnCN();
            int T7 = B->returnCN();
            if (T1 == 1) { T1 = 15; }

            if (T7 == 1) { T7 = 15; }

            if (T1 > T7) {
                std::cout << "\r\n           Player 1 is victorious!\r\n \r\n";
                P1Deck.addToDeck(A,B);
              
            }
            else if (T1 < T7) {
                std::cout << "\r\n          Player 2 is victorious!\r\n \r\n";
                P2Deck.addToDeck(A,B);
                
            }
            else {
                P3Deck.clearDeck();
                P3Deck.addToDeck(A, B);
                std::cout << "The fields of Battle are Ready! Prepare for War!\r\n \r\n";
                B = P2Deck.drawCard();
                A = P1Deck.drawCard();
                P3Deck.addToDeck(A, B);
                B = P2Deck.drawCard();
                A = P1Deck.drawCard();
                P3Deck.addToDeck(A, B);
                std::cout << "Player 1 Wields:";
                A->print();
                std::cout << "Player 2 Wields:";
                B->print();
                while (A->returnCN() == B->returnCN()) {
                    std::cout <<"The Battle Rages on...";
                    B = P2Deck.drawCard();
                    A = P1Deck.drawCard();
                    P3Deck.addToDeck(A, B);
                    B = P2Deck.drawCard();
                    A = P1Deck.drawCard();
                    P3Deck.addToDeck(A, B);
                    
                }
                if (A->returnCN() > B->returnCN()) {
                    P3Deck.printDeck();
                    std::cout << "\r\n              Player 1 is victorious! \r\n \r\n";
                    int k = P3Deck.getSize();
                    for (int g = 0; g < k; g++) {
                        std::cout << "X";
                        Card* N = new Card(9,9);
                        N = P3Deck.drawCard();
                        P1Deck.addToBackDeck(N);
                    }
                    
                    P1Deck.addExistingCards();
                 //   P1Deck.addToDeck(P3Deck);
                   
                }
                else {
                    std::cout << "\r\n              Player 2 is victorious! \r\n \r\n";
                    int k = P3Deck.getSize();
                   
                    for (int g = 0; g < k; g++) {
                        
                        Card* N = new Card(9, 9);
                        N = P3Deck.drawCard();
                        P2Deck.addToBackDeck(N);
                    }
                    P2Deck.addExistingCards();
                    //   P1Deck.addToDeck(P3Deck);
                    

                }
                
                
            }
            
        }
        
    }
    
}
War::~War()
{
    P1Deck.~deck();
    P2Deck.~deck();
    P3Deck.~deck();
    
}
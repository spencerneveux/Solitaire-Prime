//
//  Deck.hpp
//  SolitairePrime
//
//  Created by Spencer Neveux on 9/10/18.
//  Copyright © 2018 Spencer Neveux. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <iostream>
#include "Card.hpp"

// Deck header file
class Deck {
private:
    Card deckArray[52];
    int currCard;
public:
    Deck();
    Card deal();
    void refreshDeck();
    void shuffle();
    int cardsLeft();
    void showDeck();
};
#endif /* Deck_hpp */

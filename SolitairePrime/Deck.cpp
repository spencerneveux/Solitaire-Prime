//
//  Deck.cpp
//  SolitairePrime
//
//  Created by Spencer Neveux on 9/10/18.
//  Copyright © 2018 Spencer Neveux. All rights reserved.
//

#include "Deck.hpp"
#include "Card.hpp"
#include <iostream>


char suits[] = { 'S', 'H', 'D', 'C' };
char ranks[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

// Deck constructor
Deck::Deck() {
    this->currCard = 0;
    
    int index = 0;
    for (int i = 0; i < sizeof(suits); i++) {
        for (int j = 0; j < sizeof(ranks); j++) {
            deckArray[index] = Card(ranks[j], suits[i]);
            index++;
        }
    }
}

// Set deck back to default values
void Deck::refreshDeck()
{
    int index = 0;
    for (int i = 0; i < sizeof(suits); i++) {
        for (int j = 0; j < sizeof(ranks); j++) {
            deckArray[index] = Card(ranks[j], suits[i]);
            index++;
        }
    }
}

// Deal one card from deck and move counter forward one
Card Deck::deal()
{
    Card c;
    if (currCard < 52)
        c = deckArray[currCard];
        currCard++;
        return c;
}


// Shuffle deck of cards
void Deck::shuffle()
{
    for (int i = 0; i < 52; i++) {
        int randNum = rand() % 52;
        Card temp = deckArray[randNum];
        deckArray[randNum] = deckArray[i];
        deckArray[i] = temp;
    }
}

// Display deck four rows thirteen cards
void Deck::showDeck()
{
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deckArray[index].print();
            index++;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// return count of cards left
int Deck::cardsLeft()
{
    return 52 - currCard;
}

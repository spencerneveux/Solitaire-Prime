//
//  Card.cpp
//  SolitairePrime
//
//  Created by Spencer Neveux on 9/10/18.
//  Copyright © 2018 Spencer Neveux. All rights reserved.
//

#include "Card.hpp"
#include <iostream>

// null card constructor
Card::Card() {}

// Card constructor
Card::Card(char r, char s) {
    setCard(r, s);
}

// Setter
void Card::setCard(char r, char s) {
    rank = r;
    suit = s;
}

// print Card
void Card::print()
{
    std::cout << rank << suit << " ";
}


// Retrieve numerical value for rank
int Card::getValue()
{
    int value = -1;
    switch (rank)
    {
        case 'A': value = 1; break;
        case '2': value = 2; break;
        case '3': value = 3; break;
        case '4': value = 4; break;
        case '5': value = 5; break;
        case '6': value = 6; break;
        case '7': value = 7; break;
        case '8': value = 8; break;
        case '9': value = 9; break;
        case 'T': value = 10; break;
        case 'J': value = 10; break;
        case 'Q': value = 10; break;
        case 'K': value = 10; break;
            
    }
    
    return value;
}

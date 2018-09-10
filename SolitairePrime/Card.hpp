//
//  Card.hpp
//  SolitairePrime
//
//  Created by Spencer Neveux on 9/10/18.
//  Copyright © 2018 Spencer Neveux. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>

class Card {
private:
    char rank;
    char suit;
public:
    Card();
    Card(char r, char s);
    void print();
    int getValue();
};

#endif /* Card_hpp */

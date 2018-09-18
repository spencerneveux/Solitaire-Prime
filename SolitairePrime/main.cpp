// Spencer Neveux
//  CECS 282
//  SolitairePrime
// 9/17/18


#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
void displayMenu();
int getUserInput();
bool isPrime(int value);
void play(Deck deck);

using namespace std;

int main(int argc, const char * argv[]) {
    Deck deck;
    int choice;
    do {
        displayMenu();
        choice = getUserInput();
        switch (choice) {
            case 1: cout << "Creating new Deck" << endl << endl; deck.refreshDeck(); break;
            case 2: cout << "Display Deck" << endl; deck.showDeck(); break;
            case 3: cout << "Shuffling Deck" << endl << endl; deck.shuffle(); break;
            case 4: play(deck); cout<<endl<<endl; break;
            case 5: cout << "Exiting program" << endl; break;
        }
    }while(choice != 5);
    
    return 0;
}

// Method to display main menu
void displayMenu()
{
    cout << "Welcome to Solitaire Prime!" << endl;
    cout << "1) New Deck" << endl;
    cout << "2) Display Deck " << endl;
    cout << "3) Shuffle Deck" << endl;
    cout << "4) PLay Solitaire Prime" << endl;
    cout << "5) Exit" << endl;
    cout << endl;
}

int getUserInput()
{
    int userChoice = -1;
    do {
        cin >> userChoice;
        if (userChoice < 1 || userChoice > 5)
            cout << "Not a valid option. Try again" << endl;
    }while(userChoice < 1 || userChoice > 5);
    return userChoice;
}


// Method to determine if a value is prime or not
// Returns boolean
bool isPrime(int value)
{
    if (value > 1) {
        for (int i = value - 1; i > 1; i--) {
            if (value % i == 0)
                return false;
        }
        return true;
    }
    return false;
}

// Method to play Solitaire prime
void play(Deck deck)
{
    cout << "Playing Solitaire Prime!!" << endl;
    cout << endl;
    
    int pileSum = 0;
    int pileTotal = 0;
    
    while(deck.cardsLeft() != 0)
    {
        Card card = deck.deal();
        card.print();
        pileSum += card.getValue();
        int prime = isPrime(pileSum);
        if (prime == 1)
        {
            cout << "Prime: " << pileSum << endl;
            pileSum = 0;
            pileTotal++;
        }
        
        if (deck.cardsLeft() == 0 && prime != 1)
            cout << "Loser" << endl;
        else if (deck.cardsLeft() == 0 && prime == 1)
            cout << "Winner in " << pileTotal << endl;
    }
}

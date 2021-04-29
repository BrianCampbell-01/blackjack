#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "deck.h"

//#include "deck.h"
// 4 suits , 13 difftrent types of cards
const int suit_values = 4;
const int unique_cards = 13;
const int total_cards =52;

// H-heart D-diamond S-spade C-club
const char suit[suit_values] = {'H','D','S','C'};
const std::string card_values[unique_cards] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

void deck::populate () 
{
    for (int i =0; i < suit_values ; i++)
    {
        for(int j =0; j < unique_cards; j++)
        {
            card.push_back(suit[i] + card_values[j]);
        }
    }
    deck_size = 52;
}

void deck::remove_cards(int removed_cards)
{
    for(std::vector<std::string>::iterator it = card.begin(); it != card.begin()+removed_cards; ++it)
    {
        card.erase(card.begin());
    }
    deck_size-=removed_cards;
}

std::vector<std::string> deck::init()
{
    std::vector<std::string> first_hand;
    for(std::vector<std::string>::iterator it = card.begin(); it != card.begin()+2; ++it)
    {
        first_hand.push_back(*it);
    }
    remove_cards(2);
    return first_hand;
}


std::string deck::hit ()
{
    std::string drawen = *card.begin();
    card.erase(card.begin());
    deck_size--;
    return drawen;
}

//inspired by fisher yates shuffle
void deck::shuffle()
{
    std::vector<std::string> shuffled_deck;
    srand(time(NULL));
    for( int i = 52; i >0;  i--)
    {
        int rand_position = rand() % i; 
        shuffled_deck.push_back(card[rand_position]);
        card.erase(card.begin() + rand_position);
    }
    card =shuffled_deck;
}

void deck::print()
{
    for(int i = 0 ; i < total_cards; i++ )
    {
        std::cout<<card[i]<<" ";
    }
    std::cout<<std::endl;
}

void deck::count(std::vector<std::string> input)
{
    std::vector<std::string> value = input;
    int count = 0;
    for (std::vector<std::string>::iterator it = value.begin(); it != value.end() ; ++it)
    {
        count++;
    }
    std::cout<< count<<std::endl;
}

int deck::remaining_cards()
{
    return deck_size;
}
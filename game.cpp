#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include "deck.h"
#include "player.h"

game::game()
{
    player user(100);
    deck new_deck;
    current_player =  user;
    current_deck = new_deck;
}

// void game::add_players()
// {
//     int numOfPlayers;
//     std::cout<<"How many players will be playing: ";
//     std::cin>>numOfPlayers;
    
//     for(int i =0; i < numOfPlayers; i++)
//     {
//         std::string user =std::to_string(i);
//         player user(100);
//         players.push_back(user);
//     }
// }
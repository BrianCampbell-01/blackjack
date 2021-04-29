#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include "deck.h"
#include "player.h"

game::game()
{
    player current_player, dealer;
    deck current_deck;

}

bool game::check_game_state()
{
   if(bust() == true || twenty_one() == true)
   {
       return false;
   }
return true;  
}

bool game::bust()
{
    int *pointer = current_player.get_hand_value();
    if(*(pointer) > 21 && *(pointer + 1) > 21)
    {
        std::cout<<"BUST!"<<std::endl;
        return true;
    }
    return false;
}

bool game::twenty_one()
{
    int *pointer = current_player.get_hand_value();
      if(*(pointer) == 21 || *(pointer + 1) == 21)
    {
        std::cout<<"TWENTY ONE!"<<std::endl;
        return true;
    }
    return false;
}
bool game::user_hit()
{
    std::string user_input; 
    bool valid_input = true; 
    std::cout<<"\n do you want to hit or pass? ";
    std::cin>>user_input;
    if(user_input == "hit" || user_input == "Hit")
    {
        current_player.hit(current_deck.draw());
        return true; 
    }
    else if (user_input == "pass" || user_input == "Pass")
    {
        return false;
    }
    else{
        user_hit();
    }
     
}
void game::reset_table(bool &hit, bool &continue_game)
{
    hit = true;
    continue_game =true;
    current_player.empty_hand(); 
}

void game::init()
{
    bool hit = true;
    bool continue_game =true; 
    int games; 
    std::cout <<"How many games do you want to play : ";
    std::cin>>games;
    std::cout<<"\n\n*************Welcome to the cosino!***********\n";
    for(int i =0; i < games; i++)
    {
        std::cout<<"\n\n~~Next game has begun!~~"<<std::endl;
        current_deck.init();
        current_player.populate_hand(current_deck.deal());
        while(hit == true && continue_game == true)
        {
            current_player.show_hand();
            check_game_state();
            hit = user_hit();
            continue_game = check_game_state();
        } 
        current_player.show_hand();
        reset_table(hit, continue_game);
    } 
}


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

bool game::check_game_state(player player_turn)
{
   if(bust(player_turn) == true || twenty_one(player_turn) == true)
   {
       return false;
   }
return true;  
}

bool game::bust(player player_turn )
{
    int *pointer = player_turn.get_hand_value();
    if(*(pointer) > 21 && *(pointer + 1) > 21)
    {
        std::cout<<"BUST!"<<std::endl;
        return true;
    }
    return false;
}

bool game::twenty_one(player player_turn)
{
    int *pointer = player_turn.get_hand_value();
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
    std::cout<<"\nhit or pass? ";
    std::cin>>user_input;
    //std::cout<<std::endl;
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
    // current_player.empty_hand(); 
    // dealer.empty_hand();
}

int game::start_bet()
{
    int bet;
    std::cout<<"How much would you like to bet: ";
    std::cin>>bet;
    if(bet> current_player.get_balance())
    {  
        std::cout<<"\nthe bet is a bit to high dont you think?"<<std::endl;
        start_bet();
    }
    
    return bet;
}

int game::highest_hand(player current_hand)
{
    int best_hand;
    int* player_hand =  current_hand.get_hand_value();
    if(*(player_hand + 1) <= 21)
    {
        best_hand = *(player_hand + 1);
    }
    else
    {
        if (*(player_hand) > 21)
        {
            return -1;
        }
        best_hand = *(player_hand);
    }
    return best_hand; 
}


void game::Award_winner(player player_hand, player dealer_hand, int bet)
{
    int player_highest_hand = highest_hand(player_hand);
    int dealer_highest_hand = highest_hand(dealer_hand); 
    if(dealer_highest_hand > player_highest_hand )
    {
        dealer.win(bet);
        current_player.lose(bet);
    }
    else{
        dealer.lose(bet);
        current_player.win(bet);
    }
    
}

bool game::valid_hands(player player_hand, player dealer_hand)
{
    if(check_game_state(dealer)== false || check_game_state(current_player)== false)
    {
        return false; 
    }
    return true;
}

void game::display_hands()
{
    std::cout<<"Dealer: ";
    dealer.show_hand();
    std::cout<<"Player: ";
    current_player.show_hand();
}

void game::ending_hands(int bet)
{
    std::cout<<"ENDING HANDS: "<<std::endl;
    display_hands();
    if(highest_hand(current_player) > highest_hand(dealer))
    {
        std::cout<<"\nWINNINGS: " <<bet<<std::endl;
        return;
    }
    else
    {
        std::cout<<"\nLOST: " <<bet<<std::endl;
        return;
    }

    
}
void game::UI()
{
    bool hit = true;
    bool continue_game =true; 
    int games, bet; 
    std::cout<<"\n\n*************Welcome to the cosino!***********\n";
   
    while(current_player.get_balance() != 0)
    {
       
        std::cout<<"\nBalance: "<<current_player.get_balance()<<std::endl;
        bet = start_bet(); 
        std::cout<<"\n\n~~Hand was delt!~~"<<std::endl;

        current_deck.init();
        current_player.populate_hand(current_deck.deal());
        dealer.populate_hand(current_deck.deal()); 
        display_hands();
        continue_game =valid_hands(current_player, dealer);

        while(hit == true && continue_game == true)
        {
            hit = user_hit();
            if(hit == true)
                {
                    display_hands();
                }
            continue_game= valid_hands(current_player, dealer); 
            if(dealer.dealer_choice() == true)  
            {
                dealer.hit(current_deck.draw());
                continue_game= valid_hands(current_player, dealer);  
                std::cout<<"Dealer Hit! : ";
                dealer.show_hand();
            }
        }
        ending_hands(bet);
        Award_winner(current_player, dealer, bet);  
        reset_table(hit, continue_game);
        std::cout<<"*********************************************"<<std::endl;
    } 
}

void game::init()
{
    UI();
}

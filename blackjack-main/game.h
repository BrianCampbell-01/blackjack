#ifndef H_game_
#define H_game_

#include <vector>
#include "deck.h"
#include "player.h"


class game{
        deck current_deck;
        player current_player , dealer;
        public:
        game();

        void UI();
        void add_players();
        void init();

        bool check_game_state(player); 
        bool valid_hands(player,player);
        bool bust(player);
        bool twenty_one(player);

        int start_bet();
        bool user_hit(); 
        void reset_table(bool &, bool &); 

        int highest_hand(player);
        void display_hands();
        void Award_winner(player,player,int);
        void ending_hands(int);


        

};


#endif
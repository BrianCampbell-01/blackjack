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
        void add_players();
        void init();
        bool check_game_state(); 
        bool bust();
        bool twenty_one();

        bool user_hit(); 
        void reset_table(bool &, bool &); 


};


#endif
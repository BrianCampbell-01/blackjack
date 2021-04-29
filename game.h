#ifndef H_game_
#define H_game_

#include <vector>
#include "deck.h"
#include "player.h"


class game{
    public:
        deck current_deck;
        player current_player;
        game();
        void add_players();
        void init();
        void check_win(); 



};


#endif
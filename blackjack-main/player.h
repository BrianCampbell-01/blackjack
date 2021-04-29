#ifndef H_player_
#define H_player_

#include <vector>
#include <string>

class player{

    std::vector<std::string> hand;
    int balance;
    int hand_value[2];

    public:
        player();
        player(int);
        
        
        void empty_hand();
        void win(int);
        void lose(int);
        void show_hand();
        void populate_hand(std::vector<std::string>);
        void hit(std::string);
        void calculate_hand();
        int* get_hand_value();
        bool dealer_choice(); 
};




#endif
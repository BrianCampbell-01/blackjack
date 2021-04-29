#ifndef H_deck_
#define H_deck_

#include <string>
#include <vector>


class deck
{
        std::vector<std::string> card;
        int deck_size= 0;
    public:
        deck(){populate();}
        void populate();
        void print();
        void shuffle();

        void remove_cards(int);
        void init();
        
        //std::vector<std::string> init();
        std::vector<std::string> deal();
        std::string draw();
        int remaining_cards();
        



        //used in debug
        void count( std::vector<std::string>);

};
#endif
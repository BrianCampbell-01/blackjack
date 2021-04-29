#ifndef H_dealer_
#define H_dealer_

#include<vector>
#include <string>

class dealer{
    std::vector<std::string> dealers_hand;
    int house_balance = 0; 
    int hand_value[2];

    public: 
    dealer(); 
    void show_hand();
    void populate_hand(); 
    void hit(); 
  
};


#endif
#include "player.h"
#include "deck.h"
#include <iostream>
#include <vector>

player::player(int user_deposit)
{
    balance = user_deposit; 
    for(int i= 0 ; i<2;i++)
        hand_value[i] = 0;
}


void player::calculate_hand()
 {
    hand_value[0] = 0;
    hand_value[1] = 0;
    std::string value_array[13]= {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(std::vector<std::string>::iterator it = hand.begin() ; it != hand.end(); ++it)
    {
        //std::cout<<"current card is : "<<*it<<std::endl;
        std::string temp = *it;
        std::string compare;
        for(int i =0; i < temp.size(); i++)
        {
            if(i != 0)
            {
                compare += temp[i];
            }
            
        }
        for(int i =0; i < 13; i++)
        {
            if(compare == value_array[i])
            {
                if(i == 0)
                {
                    hand_value[0]+=1;
                    hand_value[1]+=11;
                }
                else if (i > 0  && i <= 9)
                {
                    hand_value[0]+=(i+1);
                    hand_value[1]+=(i+1);
                }
                else
                {
                    hand_value[0]+=10;
                    hand_value[1]+=10;
                }
            }
        } 
    }
 }

void player::empty_hand()
{
    hand.clear();
    for(int i= 0 ; i<2;i++)
        hand_value[i] = 0;
}

void player::win(int winnings)
{
    balance+=winnings;
    empty_hand();
}

void player::lose(int loses)
{
    balance-= loses;
    empty_hand();
}


void player::show_hand()
{
     if(hand.size()==0)
     {
         std::cout<<"Hand is Empty"<<std::endl;
     }
    for(std::vector<std::string>::iterator it = hand.begin(); it != hand.end(); ++it)
    {
        std::cout<<*it<< " ";
    }
    if(hand_value[0] != hand_value[1])
    {
        std::cout<<" value: "<< hand_value[0] << " or " << hand_value[1]<<std::endl;
    }
    else
    {
        std::cout<<" value: "<<hand_value[0]<<std::endl;
    }
}


 void player::populate_hand(std::vector<std::string> init)
 {
    for(std::vector<std::string>::iterator it = init.begin(); it != init.end(); ++it)
    {
        hand.push_back(*it);
    }
    calculate_hand();
 }
 

 void player::hit(std::string hit_card)
 {
     hand.push_back(hit_card);
     calculate_hand();
 }



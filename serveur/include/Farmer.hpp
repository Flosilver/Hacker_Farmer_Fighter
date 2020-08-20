#ifndef FARMER_HPP
#define FARMER_HPP

#include "config.hpp"

class Farmer : public Player
{
    protected:
        int money;
    
    public:
        Farmer();
        ~Farmer();

        Farmer& operator=(const Farmer& f);

        /* Accesseurs */
        int& getMoney() const;

        /* Methodes */
        void spend_money(int amount);
        void receive_money(int amount);
};

#endif
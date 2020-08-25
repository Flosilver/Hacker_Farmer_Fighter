#ifndef FARMER_HPP
#define FARMER_HPP

#include "config.hpp"

class Farmer : public Player
{
    protected:
        int money;      // l'argent que possède le fermier
        int stock;      // le stock de blé que possède le fermier

        int score;      // score du joueur
    
    public:
        Farmer();
        ~Farmer();

        Farmer& operator=(const Farmer& f);

        /* Accesseurs */

        const int& getMoney() const;
        const int& getStock() const;
        const int& getScore() const;

        /* Methodes */

        void spend_money(u_int amount);
        void receive_money(u_int amount);
        void add_points(u_int amount);
};

#endif
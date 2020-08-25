#ifndef HFF_HPP
#define HFF_HPP

#include "config.hpp"

/**
 * Classe représentant le jeu Hacker Farmer Fighter.
 * Hérite de la Classe Game de la librairie Rosace.
 **/
class HFF : public Game
{
    public:
        HFF();
        ~HFF();

        /* Accesseurs */

        /* Methodes */

        /* Methode de rsc::Game */
        
        void handleIncomingMessage();
};

#endif
#ifndef HFF_HPP
#define HFF_HPP

#include "config.hpp"
#include "Farmer.hpp"
#include "Entity.hpp"
#include "Field.hpp"

/**
 * Classe représentant le jeu Hacker Farmer Fighter.
 * Hérite de la Classe Game de la librairie Rosace.
 **/
class HFF : public Game
{
    protected:
        vector<sp_Farmer> players = vector<sp_Farmer>(NB_J_MAX);
        vector<sp_Field> fields = vector<sp_Field>(NB_J_MAX);
        
    public:
        HFF();
        ~HFF();

        /* Accesseurs */

        /* Methodes */

        /* Methode de rsc::Game */
        
        void handleIncomingMessage();
};

#endif
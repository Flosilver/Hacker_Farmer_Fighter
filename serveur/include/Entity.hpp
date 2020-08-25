#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "config.hpp"
//#include "Field.hpp"

enum entity_t{CROP, WELLS, TRUCK, SILO};
typedef shared_ptr<Entity> sp_Entity;

class Entity
{
    protected:
        int type;
        Vect2i pos;
        Vect2i size;
        int hp;
        int score_points;

        Entity(int type);
    
    public:
        Entity();
        ~Entity();

        Entity& operator=(const Entity& e);

        /* Accesseurs */
        
        /**
         * Retourne la position de l'entité (top-left corner).
         * */
        const Vect2i& getPos() const;
        void setPos();
        /**
         * Retourne la taille de l'entité.
         * */
        const Vect2i& getSize() const;
        const int& getType() const;

        /* Méthodes */
        
        

};

#endif
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "config.hpp"
//#include "Field.hpp"

enum entity_t{NONE, CROP, WELLS, TRUCK, SILO};
typedef shared_ptr<Entity> sp_Entity;

class Entity
{
    protected:
        int type;
        Vect2i pos;
        Vect2i size;
        int hp;
        int score_points;

        Entity(int aType);
    
    public:
        Entity();
        ~Entity();

        Entity& operator=(const Entity& e);

        /* Accesseurs */
        
        const Vect2i& getPos() const;
        void setPos(const Vect2i& v);
        const Vect2i& getSize() const;
        const int& getType() const;

        /* Méthodes */
        
        

};

#endif
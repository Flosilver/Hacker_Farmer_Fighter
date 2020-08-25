#ifndef FIELD_HPP
#define FIELD_HPP

#include "config.hpp"
#include "Entity.hpp"

//enum case_t{VOID, CROP, TRUCK, SILO, WELLS};  à déplacer!!

typedef shared_ptr<Field> sp_Field;

class Field
{
    protected:
        int map[FIELD_SIZE][FIELD_SIZE];
        sp_Entity entity_map[FIELD_SIZE][FIELD_SIZE];

    public:
        Field();
        ~Field();

        Field& operator=(const Field& f);

        /* Accesseurs */

        sp_Entity getCase(int i, int j) const;

        /* Methodes */

        void print() const;
        void place_entity(sp_Entity spe, int i, int j);
};

#endif
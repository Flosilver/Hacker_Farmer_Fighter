#ifndef FIELD_HPP
#define FIELD_HPP

#include "config.hpp"

enum case_t{VOID, CROP, TRUCK, SILO, WELLS};

class Field
{
    protected:
        int map[FIELD_SIZE][FIELD_SIZE];

    public:
        Field();
        ~Field();

        Field& operator=(const Field& f);

        /* Accesseurs */
        int& getCase(int i, int j) const;
};

#endif
#include "Field.hpp"

Field::Field(){
    for (int i=0 ; i<FIELD_SIZE ; i++){
        for (int j=0 ; j<FIELD_SIZE ; j++){
            map[i][j] = 0;
        }
    }
}
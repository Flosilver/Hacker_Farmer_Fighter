#include "Field.hpp"

Field::Field(){
    for (int i=0 ; i<FIELD_SIZE ; i++){
        for (int j=0 ; j<FIELD_SIZE ; j++){
            entity_map[i][j] = make_shared<Entity>();
        }
    }
}

Field::~Field(){
    cout << "\t***dest Field" << endl;
}

Field& Field::operator=(const Field& f){
    for (int i=0 ; i<FIELD_SIZE ; i++){
        for (int j=0 ; j<FIELD_SIZE ; j++){
            entity_map[i][j] = f.getCase(i,j);
        }
    }
    return *this;
}

/* Accesseurs */

/**
 * Retourne la valeur de la case (i, j) du terrain.
 * */
sp_Entity Field::getCase(int i, int j) const{
    // anti-mongol
    if ( i < 0 ) i = 0;
    if ( i > FIELD_SIZE ) i = FIELD_SIZE;
    if ( j < 0 ) j = 0;
    if ( j > FIELD_SIZE ) j = FIELD_SIZE;
    
    return entity_map[i][j];
}

/* Méthodes */

/**
 * Affiche le terrain dans la console
 **/
void Field::print() const{
    cout << "Field:" << endl;
    for (int i=0 ; i<FIELD_SIZE ; i++){
        for (int j=0 ; j<FIELD_SIZE ; j++){
            cout << " " << entity_map[i][j]->getType();
        }
        cout << endl;
    }
}
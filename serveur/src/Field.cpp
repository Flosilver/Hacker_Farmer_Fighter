#include "Field.hpp"

Field::Field(){
    for (int i=0 ; i<FIELD_SIZE ; i++){
        for (int j=0 ; j<FIELD_SIZE ; j++){
            entity_map[i][j] = make_shared<Entity>();
            map[i][j] = entity_map[i][j]->getType();
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
            map[i][j] = f.map[i][j];
        }
    }
    return *this;
}

/* Accesseurs */

/**
 * Retourne le shared_ptr de l'entité à la place (i,j).
 * */
sp_Entity Field::getCase(int i, int j) const{
    // anti-mongol
    if ( i < 0 ) i = 0;
    if ( i > FIELD_SIZE ) i = FIELD_SIZE;
    if ( j < 0 ) j = 0;
    if ( j > FIELD_SIZE ) j = FIELD_SIZE;
    
    return entity_map[i][j];
}

int Field::getCaseType(int i, int j) const{
    // anti-mongol
    if ( i < 0 ) i = 0;
    if ( i > FIELD_SIZE ) i = FIELD_SIZE;
    if ( j < 0 ) j = 0;
    if ( j > FIELD_SIZE ) j = FIELD_SIZE;
    
    return map[i][j];
}

/* Méthodes */

/**
 * Affiche le terrain dans la console grâce au type de l'entité sur chaque case.
 **/
void Field::print() const{
    cout << "Field:" << endl;
    for (int i=0 ; i<FIELD_SIZE ; i++){
        for (int j=0 ; j<FIELD_SIZE ; j++){
            cout << " " << map[i][j];
        }
        cout << endl;
    }
}

/**
 * Test si une entité peut être placée aux coordonnées indiquées.
 * */
bool Field::can_be_placed(sp_Entity spe, int i, int j) const{
    Vect2i entity_size = spe->getSize();
    // on vérifie s'il y a la place 
    if (i + entity_size.x > FIELD_SIZE || j + entity_size.y > FIELD_SIZE){
        return false;
    }
    for (int a=i ; a<i+entity_size.x ; a++){
        for (int b=j ; b<j+entity_size.y ; b++){
            if (map[a][b] != 0) return false;
        }
    }
    return true;
}

/**
 * Méthode permettant de placer une nouvelle entité à un emplacement.
 * S'il n'y a pas la place, la méthode renvoie 1, 0 sinon.
 * */
int Field::place_entity(sp_Entity spe, int i, int j){
    Vect2i entity_size = spe->getSize();
    // on vérifie s'il y a la place 
    if (!can_be_placed(spe,i,j)){
        return 1;   // Fail, l'entité ne peut être placée
    }
    else{
        // on positionne l'entité à la place demandé
        spe->setPos(Vect2i(i,j));

        // on met à jour les maps du Field
        for (int a=i ; a<i+entity_size.x ; a++){
            for (int b=j ; b<j+entity_size.y ; b++){
                entity_map[a][b] = spe;
                map[a][b] = spe->getType();
            }
        }
    }
}
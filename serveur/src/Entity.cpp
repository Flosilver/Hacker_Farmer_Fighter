#include "Entity.hpp"

Entity::Entity(){
    type = entity_t::NONE;
    pos = Vect2i();
    size = Vect2i();
    hp = 0;
    score_points = 0;
}

Entity::Entity(int aType){
    type = aType;
    pos = Vect2i();
    size = Vect2i();
    hp = 0;
    score_points = 0;
}

Entity::~Entity(){
    cout << "\t***dest Entity" << endl;
}

Entity& Entity::operator=(const Entity& e){
    type = e.type;
    pos = e.pos;
    size = e.size;
    hp = e.hp;
    score_points = e.score_points;
}

/* Accesseurs */

/**
 * Retourne la position de l'entité (top-left corner).
 * */
const Vect2i& Entity::getPos() const{
    return pos;
}

/**
 * Modifie la position de l'entité.
 * */
void Entity::setPos(const Vect2i& v){
    pos = v;
}

/**
 * Retourne la taille de l'entité.
 * */
const Vect2i& Entity::getSize() const{
    return size;
}

/**
 * Retourne le type de l'entité:
 * 0 = NONE
 * 1 = CROP
 * 2 = WELLS
 * 3 = TRUCK
 * 4 = SILO
 * */
const int& Entity::getType() const{
    return type;
}
#include "Farmer.hpp"

Farmer::Farmer(): Player(){
    money = 100;
    stock = 0;
}

Farmer::~Farmer(){
    cout << "\t***dest Farmer" << endl;
}

Farmer& Farmer::operator=(const Farmer& f){
    money = f.money;
    stock = f.stock;
    return *this;
}

/* Accesseurs */

/**
 * Retourne l'argent que possède le fermier.
 * */
const int& Farmer::getMoney() const{
    return money;
}

/**
 * Retourne le stock de blé que possède le fermier.
 * */
const int& Farmer::getStock() const{
    return stock;
}

/**
 * Retourne le score du fermier.
 * */
const int& Farmer::getScore() const{
    return score;
}

/* Méthodes */

/**
 * Le fermier dépense de l'argent.
 * amount > 0
 * */
void Farmer::spend_money(u_int amount){
    money -= amount;
}

/**
 * Le fermier reçoit de l'argent.
 * amount > 0
 * */
void Farmer::receive_money(u_int amount){
    money += amount;
}

/**
 * Ajoute la quantité indiquée au score du fermier.
 * */
void Farmer::add_points(u_int amount){
    score += amount;
}
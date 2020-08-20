#include "Farmer.hpp"

Farmer::Farmer(): Player(){
    money = 0;
}

Farmer::~Farmer(){
    cout << "\t***dest Farmer" << endl;
}

Farmer& Farmer::operator=(const Farmer& f){
    money = f.money;
    return *this;
}
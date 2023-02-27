#include "personne.hpp"
#include <string>

int Personne::current = 1;

Personne::Personne(String s, Position p){
    this->name = s;
    this->pos = p;
    this->id= current;
    current += 1;
}

String Personne::getName()const{
    return this->name;
}

int Personne::getId()const{
    return this->id;
}

Position Personne::getPos()const{
    return this->pos;
}

int Personne::getX()const{
    return this->getPos().x;
}

int Personne::getY()const{
    return this->getPos().y;
}

~Personne(){
    this->name=NULL;
    this->id=NULL;
    this->pos.x=NULL;
    this->pos.y=NULL;
    this->pos=NULL;
}

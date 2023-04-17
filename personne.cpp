#include "personne.hpp"
using namespace std;

int Personne::current = 1;

Personne::Personne(string s, Position p) : name(s), id(current), pos(p){
    current += 1;
}

string Personne::getName()const{
    return this->name;
}

int Personne::getId()const{
    return this->id;
}

int Personne::getX()const{
    return this->pos.x;
}

int Personne::getY()const{
    return this->pos.y;
}


Personne::~Personne(){}


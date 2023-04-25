#include "personne.hpp"
using namespace std;

int Personne::current = 1;

Personne::Personne(string s, Position p) : name(s), id(current), pos(p), isLeader(false){
    current += 1;
}

bool Personne::getIsLeader()const{
    return this->isLeader;
}

void Personne::setIsLeader(bool b){
    this->isLeader=b;
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


#include "groupe.hpp"
#include <map>
using namespace std;


Groupe::Groupe(Personne p, string n, Couleur c) : leader(p), grp_name(n), color(c), grp() {
    this->grp[p.getId()] = p;
}

Personne Groupe::getLeader()const{
    return this->leader;
}

string Groupe::getGrp_Name()const{
    return this->grp_name;
}

Couleur Groupe::getColor()const{
    return this->color;
}

map<int, Personne> Groupe::getGrp()const{
    return this->grp;
}

int Groupe::getSize()const{
    return this->grp.size();
}

Personne Groupe::findPersId(int id){
    return this->grp.at(id);
}

void Groupe::insertionPers(Personne p){
    this->grp[p.getId()]=p;
}

void Groupe::extractionPremier(){
    int key=this->grp.begin()->first;
    this->grp.erase(key);
    key=this->grp.begin()->first;
    this->leader = this->grp[key];
}

void Groupe::extractionID(int id){
    if (id == this->leader.getId()){
        extractionPremier();
    }
    else{
        this->grp.erase(id);
    }
}

/*
~Groupe(){
    this->grp_name = NULL;
    this->leader = NULL;
    this->color = NULL;
    ~this->grp();
}
*/
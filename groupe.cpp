#include "groupe.hpp"
#include <unordered_map>
#include <list>
using namespace std;


Groupe::Groupe(Personne p, string n, Couleur c) : leader(p), grp_name(n), color(c), grp(), queueAge() {
    this->grp.emplace(p.getId(), p);
    this->queueAge.push_front(p);
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

unordered_map<int, Personne> Groupe::getGrp()const{
    return this->grp;
}

int Groupe::getSize()const{
    return this->grp.size();
}

Personne Groupe::findPersId(int id){
    return this->grp.at(id);
}

void Groupe::insertionPers(Personne p){
    this->grp.emplace(p.getId(),p);
    this->queueAge.push_front(p);
}

void Groupe::extractionPremier(){
    this->leader.setIsLeader(false);
    int cle = this->queueAge.back().getId();
    this->grp.erase(cle);
    this->queueAge.pop_back();
    this->leader = this->queueAge.back();
    this->leader.setIsLeader(true); 
}

void Groupe::extractionID(int id){
    if (id == this->leader.getId()){
        extractionPremier();
    }
    else{
        this->grp.erase(id);
        auto it = this->queueAge.begin();
        while (it != this->queueAge.end()) {
            if (it->getId() == id) {
                it = this->queueAge.erase(it);
            } 
            else {
                ++it;
            }
        }
    }
}

Groupe::~Groupe(){}

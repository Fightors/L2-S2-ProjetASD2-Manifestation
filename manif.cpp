#include "manif.hpp"
#include <string>

Manif::Manif(Cortege c, int x, int y) : march(&c), road(), largeur(x), longueur(y){}

int Manif::getLongueur(){
    return this->longueur;
}

int Manif::getLargeur(){
    return this->largeur;
}

Personne Manif::findPersId(int id){
    return this->march->accesPersId(id);
}

std::list<Personne> Manif::getLeadersMarching() {
    std::list<Personne> leaders;

    for (Personne p : road) {
        if (p.getIsLeader()) {
            leaders.push_back(p);
        }
    }
    return leaders;
}

void Manif::simStep(){

}

void Manif::extractionID(int id){
    this->march->suppressionPersId(id);
    auto it = this->road.begin();
    while (it != this->road.end()) {
        if (it->getId() == id) {
            it = this->road.erase(it);
        } 
        else {
            ++it;
        }
    }
}

void Manif::endTest(){

}

Manif::~Manif(){}
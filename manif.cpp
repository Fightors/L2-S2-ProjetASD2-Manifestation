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

void Manif::simStep(int step){
    if(step<=int(this->march->getProcession().size())){
        Groupe G = this->march->getProcession()[step];
        for(std::list<Personne>::iterator it = G.getQueueAge().begin(); it != G.getQueueAge().end(); it++){
            if(int(this->road.size())==this->largeur*this->longueur){
                this->road.pop_back();
            } 
            this->road.push_front(*it);
        }
    }
    else{
        this->road.pop_back();
    } 
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

bool Manif::endTest(){
    return this->road.size()==0;
}

Manif::~Manif(){}
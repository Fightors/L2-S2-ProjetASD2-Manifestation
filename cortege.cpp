#include "cortege.hpp"
#include <vector>
#include <algorithm>
using namespace std;

Cortege::Cortege(string n): name(n), procession(){}

string Cortege::getName(){
    return this->name;
} 

std::vector<Groupe> Cortege::getProcession(){
    return this->procession;
}

void Cortege::insertionGrp(Groupe g){
    this->procession.push_back(g);
}

void Cortege::suppressionGrp(string n){
    for (unsigned i=0; i<this->procession.size(); ++i){
        if (this->procession[i].getGrp_Name()==n){
            this->procession.erase(this->procession.begin()+i);
        }
    }
}

Personne Cortege::accesPersId(int id){
    Personne find = this->procession[0].getLeader();
    for (unsigned i=0; i<this->procession.size(); ++i){
        if(this->procession[i].findPersId(id).getId()==id){
            Personne find = this->procession[i].findPersId(id);
        }
    }
    return find;
}

void Cortege::suppressionPersId(int id){
    for (unsigned i=0; i<this->procession.size(); ++i){
        if(this->procession[i].findPersId(id).getId()==id){
            this->procession[i].extractionID(id);
        }
    }
}

void Cortege::sortColor() {
    std::sort(procession.begin(), procession.end(),[](const Groupe& g1, const Groupe& g2) {
        return g1.getColor().nom() < g2.getColor().nom();
    });
}

void Cortege::sortSize() {
    std::sort(procession.begin(), procession.end(),[](const Groupe& g1, const Groupe& g2) {
        return g1.getSize() < g2.getSize();
    });
}


Cortege::~Cortege(){}
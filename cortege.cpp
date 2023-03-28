#include "cortege.hpp"
#include <vector>
using namespace std;

Cortege::Cortege(string n): name(n), procession(){}

void Cortege::insertionGrp(Groupe g){
    this->procession.push_back(g);
}

void Cortege::suppressionGrp(string n){
    for (unsigned i=0; i<this->procession.size(); ++i){
        if (this->procession[i].getGrp_Name()==n){
            this->procession.erase();
        }
    }
}

Personne Cortege::accesPersId(int id){
    
}

void Cortege::suppressionPersId(int id){

}

void Cortege::sortColor(){

}

void Cortege::sortSize(){

}

Cortege::~Cortege(){}
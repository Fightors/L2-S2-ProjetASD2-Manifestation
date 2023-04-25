#include "cortege.hpp"
#include <vector>
using namespace std;

Cortege::Cortege(string n): name(n), procession(){}

string Cortege::getName(){
    return this->name;
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

void Cortege::sortColor(){
    //vector<string> ordre_couleur=("noir","rouge","vert","jaune","bleu","magenta","cyan","blanc");
    //sort(this->procession.begin(), this->procession.end(), [&](const string& a, const string& b))

}

void Cortege::sortSize(){
    Groupe k = this->procession[0];
    for (unsigned j = 0 ; j<this->procession.size() ; j++){
            for (unsigned i=0 ; i<this->procession.size()-1 ; i++){
                if (this->procession[i].getSize() > this->procession[i+1].getSize()){
                    k = this->procession[i];
                    this->procession[i] = this->procession[i+1] ;
                    this->procession[i+1] = k ;
                }
            }
        }
}

Cortege::~Cortege(){}
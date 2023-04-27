#include "cortege.hpp"
#include <vector>
#include <algorithm>
using namespace std;

/// Constructeur du Cortège
/// @param n le nom du Cortège
Cortege::Cortege(string n): name(n), procession(){}

/// Getter pour le nom du cortège
/// @return string
string Cortege::getName(){
    return this->name;
} 

/// Getter pour la procession
/// @return vector de Groupe
std::vector<Groupe> Cortege::getProcession(){
    return this->procession;
}

/// Insère un nouveau Groupe dans la procession
/// @param g le Groupe inséré
void Cortege::insertionGrp(Groupe g){
    this->procession.push_back(g);
}

/// Supprime un Groupe du Cortège à partir d'un nom
/// @param n le nom du groupe 
void Cortege::suppressionGrp(string n){
    for (unsigned i=0; i<this->procession.size(); ++i){
        if (this->procession[i].getGrp_Name()==n){
            this->procession.erase(this->procession.begin()+i);
        }
    }
}

/// On accède à une personne du Cortège à partir de son id
/// @param id l'id de la personne
/// @return Personne
Personne Cortege::accesPersId(int id){
    Personne find = this->procession[0].getLeader();
    for (unsigned i=0; i<this->procession.size(); ++i){
        if(this->procession[i].findPersId(id).getId()==id){
            Personne find = this->procession[i].findPersId(id);
        }
    }
    return find;
}

/// Supprime une personne du Cortège à partir de son id
/// @param id l'id de la personne
void Cortege::suppressionPersId(int id){
    for (unsigned i=0; i<this->procession.size(); ++i){
        if(this->procession[i].findPersId(id).getId()==id){
            this->procession[i].extractionID(id);
        }
    }
}

/// Trie tous les Groupes présent dans le Cortège à partir de leur couleur
void Cortege::sortColor() {
    std::sort(procession.begin(), procession.end(),[](const Groupe& g1, const Groupe& g2) {
        return g1.getColor().nom() < g2.getColor().nom();
    });
}

/// Trie tous les Groupes présent dans le Cortège à partir de leur taille
void Cortege::sortSize() {
    std::sort(procession.begin(), procession.end(),[](const Groupe& g1, const Groupe& g2) {
        return g1.getSize() < g2.getSize();
    });
}

/// Destructeur de Cortège
Cortege::~Cortege(){}
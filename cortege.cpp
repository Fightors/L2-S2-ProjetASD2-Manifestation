#include "cortege.hpp"
#include <vector>
#include <algorithm>
using namespace std;

/// Constructeur du Cortège
/// @param n le nom du Cortège
Cortege::Cortege(string n): name(n), procession(){}

/// Getter pour le nom du cortège
/// @return string
string Cortege::getName()const{
    return this->name;
} 

/// Getter pour la procession
/// @return vector de Groupe*
std::list<Groupe*> Cortege::getProcession()const{
    return this->procession;
}

/// Insère un nouveau Groupe dans la procession
/// @param g le Groupe inséré
void Cortege::insertionGrp(Groupe* g){
    this->procession.push_back(g);
}

/// Supprime un Groupe du Cortège à partir d'un nom
/// @param n le nom du groupe 
void Cortege::suppressionGrp(string n){
    for (auto it = this->procession.begin(); it != this->procession.end(); it++){
        if ((*it)->getGrp_Name()==n){
            this->procession.erase(it);
        }
    }
}

/// On accède à une personne du Cortège à partir de son id
/// @param id l'id de la personne
/// @return Personne*
Personne* Cortege::accesPersId(int id)const{
    Personne* find = new Personne("-",{0,0});
    for (auto it = this->procession.begin(); it != this->procession.end(); it++){
        if((*it)->findPersId(id)->getId()==id){
            find = (*it)->findPersId(id);
        }
    }
    return find;
}

/// Supprime une personne du Cortège à partir de son id
/// @param id l'id de la personne
void Cortege::suppressionPersId(int id){
    for (auto it = this->procession.begin(); it != this->procession.end(); it++){
        if((*it)->findPersId(id)->getId()==id){
            (*it)->extractionID(id);
        }
    }
}

/// Trie tous les Groupes présent dans le Cortège à partir de leur couleur
void Cortege::sortColor() {
    procession.sort([]( Groupe*& g1,  Groupe*& g2) {
        return g1->getColor().nom() < g2->getColor().nom();
    });
}

/// Trie tous les Groupes présent dans le Cortège à partir de leur taille
void Cortege::sortSize() {
     procession.sort([]( Groupe*& g1, Groupe*& g2) {
        return g1->getSize() < g2->getSize();
    });
}


/// Affiche l'intgralité d'un Cortège
void Cortege::afficherCortege()const{
    for(auto it = procession.begin(); it !=  procession.end(); it++){
        (*it)->afficherGroupe();
    }
}

/// On accède à une couleur de Groupe dans le Cortège
/// @param id l'id de la personne du Groupe
/// @return Couleur
Couleur Cortege::getColorGrp(int id)const{
    for(auto it = procession.begin(); it !=  procession.end(); it++){
        if((*it)->findPersId(id)->getId()==id){
            return (*it)->getColor();
        }
    }
    Couleur NewC = Couleur::creer("blanc"); 
    return NewC;
} 

/// Destructeur de Cortège
Cortege::~Cortege(){}
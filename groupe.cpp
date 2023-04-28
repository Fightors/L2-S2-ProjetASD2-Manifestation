#include "groupe.hpp"
#include <unordered_map>
#include <list>
using namespace std;

/// Constructeur de Groupe
/// @param p La première Personne du Groupe @param n Nom du Groupe @param c Couleur du Groupe
Groupe::Groupe(Personne p, string n, Couleur c) : leader(p), grp_name(n), color(c), grp(), queueAge() {
    insertionPers(p);
    p.setIsLeader(true);
}
/// Getter du Leader du Groupe
/// @return Personne
Personne Groupe::getLeader()const{
    return this->leader;
}

/// Getter de la liste d'ancienneté du Groupe
/// @return std::list<Personne>
std::list<Personne> Groupe::getQueueAge()const{
    return this->queueAge;
} 

/// Getter du nom du Groupe
/// @return string
string Groupe::getGrp_Name()const{
    return this->grp_name;
}

/// Getter de la couleur du Groupe
/// @return Couleur
Couleur Groupe::getColor()const{
    return this->color;
}

/// Getter du Groupe
/// @return unordered_map<int,Personne>
unordered_map<int, Personne> Groupe::getGrp()const{
    return this->grp;
}

/// Getter de la taille du Groupe
/// @return int
int Groupe::getSize()const{
    return this->grp.size();
}

/// Trouve une Personne dans le Groupe avec son id
/// @param id
/// @return Personne
Personne Groupe::findPersId(int id){
    return this->grp.at(id);
}

/// Insère une nouvelle Personne dans le Groupe
/// @param p
void Groupe::insertionPers(Personne p){
    this->grp.emplace(p.getId(),p);
    this->queueAge.push_front(p);
}

/// Retire le Leader actuel du Groupe
/// Actualise le Groupe et la liste d'ancienneté
void Groupe::extractionPremier(){
    this->leader.setIsLeader(false);
    int cle = this->queueAge.back().getId();
    this->grp.erase(cle);
    this->queueAge.pop_back();
    this->leader = this->queueAge.back();
    this->leader.setIsLeader(true); 
}

/// Extrait une personne avec son id
/// @param id
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

void Groupe::afficherGroupe(){
    cout << grp_name << endl;
    for(auto it = queueAge.begin(); it !=  queueAge.end(); it++){
        cout << "Id : " << it->getId() << " Nom : " << it->getName() << endl;
    }
    cout << endl;
}

/// Destructeur de Groupe
Groupe::~Groupe(){}

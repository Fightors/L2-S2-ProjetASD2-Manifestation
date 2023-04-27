#include "manif.hpp"
#include <string>

/// Constructeur de Manif
/// @param c Le Cortège @param x largeur de la grille @param y longueur de la grille
Manif::Manif(Cortege c, int x, int y) : march(&c), road(), largeur(x), longueur(y){}

/// Getter pour la longueur de la grille
/// @return int
int Manif::getLongueur(){
    return this->longueur;
}

/// Getter pour la largeur de la grille
/// @return int
int Manif::getLargeur(){
    return this->largeur;
}

/// Trouve une Personne dans la manif à partir de l'id
/// @param id l'id de la Personne
/// @return Personne
Personne Manif::findPersId(int id){
    return this->march->accesPersId(id);
}

/// Renvoie une liste de tous les leaders présents dans la manif actuellement
/// @return std::list<Personne>
std::list<Personne> Manif::getLeadersMarching() {
    std::list<Personne> leaders;

    for (Personne p : road) {
        if (p.getIsLeader()) {
            leaders.push_back(p);
        }
    }
    return leaders;
}

/// Simule une étape dans la progression de la manif
/// @param step Le numéro de l'étape à simuler
void Manif::simStep(int step){
    Position currentPos={1,1}; 

    if(step<=int(this->march->getProcession().size())){
        Groupe G = this->march->getProcession()[step-1];

        for(std::list<Personne>::iterator it = G.getQueueAge().begin(); it != G.getQueueAge().end(); it++){
            std::cout << it->getId() << std::endl;

            if(int(this->road.size())==this->largeur*this->longueur){
                this->road.pop_back();
            } 

            std::cout << it->getName() << std::endl;
            this->road.push_front(*it);
        }

        for(std::list<Personne>::iterator it2 = this->road.begin(); it2 != this->road.end(); it2++){
            it2->setX(currentPos.x);
            it2->setY(currentPos.y);
            currentPos.x+=1;

            if(currentPos.x == this->largeur+1){
                currentPos.y+=1;
                currentPos.x=1;
            }
        } 
    }       
    else{
        currentPos={(step-this->longueur*this->largeur)%this->largeur,(step-(step-this->longueur*this->largeur)%this->largeur)/largeur+1};
        this->road.pop_back();
        for(std::list<Personne>::iterator it2 = this->road.begin(); it2 != this->road.end(); it2++){
            it2->setX(currentPos.x);
            it2->setY(currentPos.y);
            currentPos.x+=1;

            if(currentPos.x == this->largeur+1){
                currentPos.y+=1;
                currentPos.x=1;
            }
        } 
    } 
}


/// Supprime une Personne de la Manif à partir de son id
/// @param id L'id de la Personne
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

/// Arrête la simulation quand la manif se finit
/// @return bool
bool Manif::endTest(){
    return this->road.size()==0;
}

/// Destructeur de Manif
Manif::~Manif(){}
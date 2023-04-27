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

    for (Personne* p : road) {
        if (p->getIsLeader()) {
            leaders.push_back(*p);
        }
    }
    return leaders;
}

/// Simule une étape dans la progression de la manif
/// @param step Le numéro de l'étape à simuler
void Manif::simStep(int step, int Gr, int Per){
    int temp = largeur;
    while(temp>0){
        std::vector<Groupe>::iterator it = this->march->getProcession().begin();
        std::advance(it,Gr);
        std::list<Personne>::iterator yt = (it->getQueueAge()).begin();
        std::advance(yt,Per);
        road.push_front(&(*yt));
        temp--;
        std::list<Personne>::iterator tempo = (it->getQueueAge()).begin();
        std::advance(tempo,this->march->getProcession().size());
        if(yt==tempo){
            Gr+=1;
            Per=0;
        }
        else{
            Per+=1;
        }
    }
}


/// Supprime une Personne de la Manif à partir de son id
/// @param id L'id de la Personne
void Manif::extractionID(int id){
    this->march->suppressionPersId(id);
    auto it = this->road.begin();
    while (it != this->road.end()) {
        if ((*it)->getId() == id) {
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

void Manif::afficherManif() const {
    for (int i = longueur - 1; i >= 0; --i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < largeur; j++) {
            auto tt = road.begin();
            if ((*tt)!=nullptr ) { 
                std::cout << (*tt)->getName()[0];
            } else {
                std::cout << "-"; 
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int j = 1; j <= largeur; ++j) {
        std::cout << j << " ";
    }
    std::cout << std::endl;
}

void Manif::afficherParticipants() const {
    march->afficherCortege();
}

/// Destructeur de Manif
Manif::~Manif(){}
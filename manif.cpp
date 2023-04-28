#include "manif.hpp"
#include <string>

/// Constructeur de Manif
/// @param c Le Cortège @param x largeur de la grille @param y longueur de la grille
Manif::Manif(Cortege* c, int x, int y) : march(c), road(), largeur(x), longueur(y){}

/// Getter pour la longueur de la grille
/// @return int
int Manif::getLongueur()const{
    return this->longueur;
}

/// Getter pour la largeur de la grille
/// @return int
int Manif::getLargeur()const{
    return this->largeur;
}

/// Trouve une Personne dans la manif à partir de l'id
/// @param id l'id de la Personne
/// @return Personne*
Personne* Manif::findPersId(int id)const{
    return this->march->accesPersId(id);
}

/// Renvoie une liste de tous les leaders présents dans la manif actuellement
/// @return std::list<Personne*>
std::list<Personne> Manif::getLeadersMarching()const{
    std::list<Personne> leaders;

    for (int i=0; i<largeur;i++) {
        for (int j=0; j<largeur;j++) {
            if (road[i][j]->getIsLeader()) {
                leaders.push_back(*road[i][j]);
            }
        }
    }
    return leaders;
}

/// Initialise la route de manifestation
void Manif::initRoad(){
    road = new Personne**[largeur];
    for (int i = 0; i < longueur; i++) {
        road[i] = new Personne*[longueur];
    }

    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {
            road[i][j] = new Personne("-", {0, 0});
        }
    }
}


/// Simule une étape dans la progression de la manif
/// @param step Le numéro de l'étape à simuler
void Manif::simStep(int step){
    for (int i = longueur - 1; i > 0; i--) {
        for (int j = 0; j < largeur; j++) {
            if (road[i][j]->getName() != "-") {
                road[i][j]->setY(road[i][j]->getY() + 1);
            }
            road[i][j] = road[i-1][j];
        }
    }
    
    for(int i=1; i<=largeur;i++){
        Personne* temP = this->march->accesPersId(largeur*step+i);
        temP->setY(1);
        temP->setX(i);
        road[0][i-1] = temP;
    }
}

/// Simule une étape dans la progression de la manif Deuxième Version Non-Complète !
/// @param step Le numéro de l'étape à simuler
void Manif::simStepTwo(int step){
    if(road[longueur-1][largeur-1]->getName()!="-"){
        for (int i = longueur - 1; i > 0; i--) {
            for (int j = 0; j < largeur; j++) {
                if(i!=longueur-1 && j!=largeur-1){
                    if(j==largeur-1){
                        road[i][j]->setY(road[i][j]->getY() + 1);
                        road[i][j]->setX(0);
                    }
                    else{
                        road[i][j]->setX(road[i][j]->getX()+1);
                    }
                }
            }
        }
    }
    else{
        simStep(step);
    }
}

/// Supprime une Personne de la Manif à partir de son id
/// @param id L'id de la Personne
void Manif::extractionID(int id){
    for (int i=0; i<largeur;i++) {
        for (int j=0; j<largeur;j++) {
            if (road[i][j]->getId()) {
                road[i][j]=nullptr;
            }
        }
    }
}

/// Arrête la simulation quand la manif se finit
/// @return bool
bool Manif::endTest()const{
    for (int i=0; i<longueur;i++) {
        for (int j=0; j<largeur;j++) {
            if (road[i][j]->getName()!="-") {
                return false;
            }
        }
    }
    return true;
}


/// Affiche la manifestation dasn son intégralité
void Manif::afficherManif() const {
    for (int i = longueur - 1; i >= 0; --i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < largeur; ++j) {
            if (road[i][j]->getName()!="-"){
                Couleur C = this->march->getColorGrp(road[i][j]->getId());
                C.afficher(std::cout,std::string(1,road[i][j]->getName()[0]));
            }
            else{
                std::cout << road[i][j]->getName()[0];
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
Manif::~Manif() {
    // Libérer chaque objet Personne stocké dans les tableaux
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {
            delete road[i][j];
        }
        delete[] road[i];
    }
    // Libérer le tableau de tableaux
    delete[] road;

    // Libérer les groupes du Cortège
    delete march;
}


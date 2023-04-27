#include "personne.hpp"
using namespace std;

/// Variable constante pour l'id des nouvelles Personnes
int Personne::current = 1;

/// Constructeur de Personne
/// L'id est déterminé edans le constructeur selon l'ordre de création
/// @param s Nom de la Personne  @param p Position de la Personne
Personne::Personne(string s, Position p) : name(s), id(current), pos(p), isLeader(false){
    current += 1;
}

/// Getter pour savoir si la Personne est Leader
/// @return bool
bool Personne::getIsLeader()const{
    return this->isLeader;
}

/// Setter pour l'état de Leader
/// @param b true ou false pour leader ou non
void Personne::setIsLeader(bool b){
    this->isLeader=b;
}

/// Getter pour le nom d'une Personne
/// @return string
string Personne::getName()const{
    return this->name;
}

/// Getter pour l'id d'une Personne
/// @return int
int Personne::getId()const{
    return this->id;
}

/// Getter pour la Position en X d'une Personne
/// @return int
int Personne::getX()const{
    return this->pos.x;
}

/// Setter pour la Position en X d'une Personne
/// @param x    La valeur en X
void Personne::setX(int x){
    this->pos.x=x;
}

/// Getter pour la Position en Y d'une Personne
/// @return int
int Personne::getY()const{
    return this->pos.y;
}

/// Setter pour la Position en Y d'une Personne
/// @param y La valeur en Y
void Personne::setY(int y){
    this->pos.y=y;
}

/// Destructeur de Personne
Personne::~Personne(){}


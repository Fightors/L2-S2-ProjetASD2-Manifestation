#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <time.h>
#include "manif.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// choix aléatoire d'un élément dans l'ensemble passé en paramètre
std::string choisir_prenom(const set<std::string>& s)
{
   int n = s.size(),
       k = rand() % n;

   auto it = s.begin();
   std::advance(it, k);
   return *it;
}

////////////////////////////////////////////////////////////////////////////////
// lecture du fichier des prénoms
void lecture_fichier_prenoms(set<std::string>& ens)
{
   ifstream fin;
   fin.open("nat2021.csv", ios::in);
   string line, mot;

   while (fin >> line)
   {
      istringstream is(line);
      getline(is, mot, ';');
      getline(is, mot, ';');
      ens.insert(mot);
   }
   fin.close();
}


////////////////////////////////////////////////////////////////////////////////
int main()
{/*
   // initialisation du générateur de nombres aléatoires
   srand(time(0));

   // lecture du fichier des prénoms
   set<std::string> ens_prenom;
   lecture_fichier_prenoms(ens_prenom);

   // lecture du fichier des corteges
   ifstream fcor;
   fcor.open("declaration.csv", ios::in);
   std::string line, nom, couleur, str, sujet;
   int taille;
   
   getline(fcor, sujet);

   // TODO : création d'un cortège
   Cortege C = new Cortege("CGT");

   while (fcor >> line)
   {
      istringstream is(line);
      getline(is, nom, ';');
      getline(is, couleur, ';');
      getline(is, str, ';');
      taille = stoi(str);

      cout << nom << ';' << couleur << ';' << taille << endl;

      // TODO : création des groupes
      // appeler choisir_prenom(ens_prenom) pour choisir un prénom
   }
   fcor.close();
*/

   // TODO
   Position pos1;
   pos1.x=5;
   pos1.y=7;

   Personne P1 = {"jean",pos1};
   Personne P2 = {"blob",pos1};

   Couleur C1= Couleur::ROUGE;
   Couleur C2= Couleur::JAUNE;

   Groupe G1 = {P1,"CGT",C1};
   G1.insertionPers(P2);
   G1.extractionID(2);

   Cortege CORT = {"OH"};
   cout << CORT.getName() << endl;
   CORT.insertionGrp(G1);
   cout << CORT.accesPersId(1).getId() << endl;
   CORT.suppressionPersId(1);
   CORT.suppressionGrp("CGT");
   return 0;
}

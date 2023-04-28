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
{
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
   Cortege* Cort = new Cortege("CGT");
   int larg = 5;
   int longu = 7;
   int step = 0;

   /*cout << "Largeur et longueur de la grille de manifestations ?" << endl;
   cin >> larg;
   cin >> longu;
   */
   while (fcor >> line)
   {
      istringstream is(line);
      getline(is, nom, ';');
      getline(is, couleur, ';');
      getline(is, str, ';');
      taille = stoi(str);
      Personne* Leader = new Personne (choisir_prenom(ens_prenom),{0,0}); 
      Couleur NewC = Couleur::creer(couleur);
      Groupe* NewG = new Groupe (Leader, nom, NewC);
      for(int i=0;i<taille-1;i++){
         Personne* NewP = new Personne (choisir_prenom(ens_prenom),{0,0});
         NewG->insertionPers(NewP); 
      }
      Cort->insertionGrp(NewG);
   }
   fcor.close();
   Manif* fete = new Manif (Cort, larg, longu);
   fete->initRoad();
   fete->afficherParticipants();
   
   cout << "Etape : " << step << endl;
   fete->simStep(step);
   fete->afficherManif();
   step+=1;
   while(fete->endTest()==false){
      cout << "Etape : " << step << endl;
      fete->simStep(step);
      fete->afficherManif();
      step+=1;
   }
   cout << "Fin de manifestation !" << endl;
   return 0;
}
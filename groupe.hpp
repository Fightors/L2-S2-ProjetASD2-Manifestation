#ifndef GROUPE_HPP
#define GROUPE_HPP

#include "personne.hpp"
#include "couleur.hpp"
#include <string>
#include <map>


class Groupe {
    private :
        Personne leader;
        std::string grp_name;
        Couleur color;
        std::map<int, Personne> grp;

    public :
        Groupe(Personne p, std::string n, Couleur c);
        Personne getLeader()const;
        std::string getGrp_Name()const;
        Couleur getColor()const;
        std::map<int, Personne> getGrp()const;
        int getSize()const;
        Personne findPersId(int id);

        void insertionPers(Personne p);
        void extractionPremier();
        void extractionID(int id);
        ~Groupe();
};

#endif

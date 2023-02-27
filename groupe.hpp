#ifndef GROUPE_HPP
#define GROUPE_HPP

#include "personne.hpp"
#include "couleur.hpp"
#include <string>
#include <list>


class Groupe {
    private :
        Personne leader;
        String grp_name;
        Couleur color;
        std::list<Personne> grp;

    public :
        Groupe(Personne p, String n, Couleur c);
        Personne getLeader()const;
        String getGrp_Name()const;
        Couleur getColor()const;
        std::list getGrp()const;
        int getSize()const;
        Personne findPersId(int i);

        void insertionPers(Personne p);
        void extractionPremier();
        void extractionID(int i);
        void extractionName(String n);
        ~Groupe();
};

#endif

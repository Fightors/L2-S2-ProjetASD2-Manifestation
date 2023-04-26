#ifndef GROUPE_HPP
#define GROUPE_HPP

#include "personne.hpp"
#include "couleur.hpp"
#include <string>
#include <unordered_map>
#include <list>


class Groupe {
    private :
        Personne leader;
        std::string grp_name;
        Couleur color;
        std::unordered_map<int, Personne> grp;
        std::list<Personne> queueAge;

    public :
        Groupe(Personne p, std::string n, Couleur c);
        Personne getLeader()const;
        std::string getGrp_Name()const;
        Couleur getColor()const;
        std::unordered_map<int, Personne> getGrp()const;
        int getSize()const;
        Personne findPersId(int id);
        std::list<Personne> getQueueAge()const;

        void insertionPers(Personne p);
        void extractionPremier();
        void extractionID(int id);
        ~Groupe();
};

#endif

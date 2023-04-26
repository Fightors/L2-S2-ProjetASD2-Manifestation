#ifndef MANIF_HPP
#define MANIF_HPP

#include "cortege.hpp"
#include <string>

class Manif {
    private :
        Cortege* march;
        std::list<Personne> road;
        int largeur;
        int longueur;
        
    public :
        Manif(Cortege c, int x, int y);
        Personne findPersId(int id);
        std::list<Personne> getLeadersMarching();
        int getLongueur();
        int getLargeur();

        void simStep(int step);
        void extractionID(int id);
        bool endTest();
        ~Manif();
};

#endif

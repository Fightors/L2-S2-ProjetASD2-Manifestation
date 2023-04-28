#ifndef MANIF_HPP
#define MANIF_HPP

#include "cortege.hpp"
#include <string>

class Manif {
    private :
        Cortege* march;
        Personne*** road;
        int largeur;
        int longueur;
        
    public :
        Manif(Cortege* c, int x, int y);
        Personne* findPersId(int id)const;
        std::list<Personne> getLeadersMarching()const;
        int getLongueur()const;
        int getLargeur()const;

        void initRoad();
        void afficherParticipants() const;
        void simStep(int step);
        void simStepTwo(int step);
        void extractionID(int id);
        bool endTest()const;
        void afficherManif() const;
        ~Manif();
};

#endif

#ifndef MANIF_HPP
#define MANIF_HPP

#include "cortege.hpp"
#include <string>

class Manif {
    private :
        Cortege march;
        
    public :
        Manif(Cortege c);
        Personne findPersId(int id);
        std::list<Personne> getLeadersMarching();
        
        void simStep();
        void extractionID(int id);
        void endTest();
        ~Manif();
};

#endif

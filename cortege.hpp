#ifndef CORTEGE_HPP
#define CORTEGE_HPP

#include "groupe.hpp"
#include <vector>

class Cortege {
    private :
        std::string name;
        std::list<Groupe*> procession;

    public :
        Cortege(std::string n);
        std::string getName()const;
        std::list<Groupe*> getProcession()const;
        Couleur getColorGrp(int id)const;
        void insertionGrp(Groupe* g);
        void suppressionGrp(std::string s);
        Personne* accesPersId(int id)const;
        void suppressionPersId(int id);
        void sortColor();
        void sortSize();
        void afficherCortege()const;
        ~Cortege();
};

#endif

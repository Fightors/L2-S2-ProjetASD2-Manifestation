#ifndef CORTEGE_HPP
#define CORTEGE_HPP

#include "groupe.hpp"
#include <vector>

class Cortege {
    private :
        std::string name;
        std::vector<Groupe> procession;

    public :
        Cortege(std::string n);
        std::string getName();
        std::vector<Groupe> getProcession();
        void insertionGrp(Groupe g);
        void suppressionGrp(std::string s);
        Personne accesPersId(int id);
        void suppressionPersId(int id);
        void sortColor();
        void sortSize();
        void afficherCortege();
        ~Cortege();
};

#endif

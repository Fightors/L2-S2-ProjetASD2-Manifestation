#ifndef CORTEGE_HPP
#define CORTEGE_HPP

#include "groupe.hpp"
#include <list>

class Cortege {
    private :
        std::string name;
        std::list<Groupe> procession;

    public:
        Cortege(std::string n);
        void insertionGrp(Groupe g);
        void suppressionGrp(std::string s);
        ~Cortege();
};

#endif

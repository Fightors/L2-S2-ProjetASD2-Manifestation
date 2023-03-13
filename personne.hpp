#ifndef PERSONNE_HPP
#define PERSONNE_HPP
#include <string>

struct Position{
    int x,y;
};

class Personne {
    private :
        std::string name;
        int id;
        Position pos;
        static int current;
    
    public :
        Personne(std::string s, Position p);
        std::string getName()const;
        int getId()const;
        Position getPos()const;
        int getX()const;
        int getY()const;
        ~Personne();
};

#endif

#ifndef PERSONNE_HPP
#define PERSONNE_HPP
#include <string>

struct Position{
    int x,y;
};

class Personne {
    private :
        String name;
        int id;
        Position pos;
        static int current;
    
    public :
        Personne(String s, Position p);
        String getName()const;
        int getId()const;
        Position getPos()const;
        int getX()const;
        int getY()const;
        ~Personne();
};

#endif

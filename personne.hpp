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
        bool isLeader;
        static int current;
    
    public :
        Personne(std::string s, Position p);
        std::string getName()const;
        int getId()const;
        Position getPos()const;
        int getX()const;
        void setX(int x);
        int getY()const;
        void setY(int y);
        void setIsLeader(bool b);
        bool getIsLeader()const;
        ~Personne();
};

#endif

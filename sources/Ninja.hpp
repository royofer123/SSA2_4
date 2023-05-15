#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel {
    class Ninja: public Character{
        private:
        int speed;
        public:
       Ninja(string name, int hit_point,Point& location, int speed): Character(name, location, hit_point) , speed(speed){}
       // Ninja(Ninja&& other) noexcept   : Character(std::move(other)), speed(std::__exchange(other.speed, 0)) {}
        ~Ninja() = default; 
        virtual void move(Character *other);
        virtual void slash(Character *other);
        string print() override;
        int getSpeed();  
    };
    class OldNinja:public Ninja{
        public:
        OldNinja(string name , Point location);
    };
       class YoungNinja:public Ninja{
        public:
        YoungNinja(string name , Point location);
    };
       class TrainedNinja:public Ninja{
        public:
        TrainedNinja(string name , Point location);
    };
};
 #endif

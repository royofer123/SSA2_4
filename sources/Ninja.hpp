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
        Ninja(string&& name, int healthPoints, Point location, int speed) : Character(std::move(name), location, healthPoints), speed(speed) {}
       // Ninja(Ninja&& other) noexcept   : Character(std::move(other)), speed(std::__exchange(other.speed, 0)) {}
       // ~Ninja() override;
        virtual void move(Character *other);
        virtual void slash(Character *other);
        string print() override;
        int getSpeed();  
    };
    class OldNinja:public Ninja{
        public:
        OldNinja(string&& name , Point location);
    };
       class YountNinja:public Ninja{
        public:
        YountNinja(string&& name , Point location);
    };
       class TrainedNinja:public Ninja{
        public:
        TrainedNinja(string&& name , Point location);
    };
};
 #endif

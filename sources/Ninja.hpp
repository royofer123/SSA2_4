#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>
#include <string>
using namespace std;

const int NINJA_DMG=40;

namespace ariel {
    class Ninja: public Character{
        private:
        int speed;
        protected:
        int getSpeed() const;
        //Constructor
        Ninja(const std::string &name,Point location, const int healthPoints, int speed) :
            Character(name, location, healthPoints), speed(speed) {}
        public:
        //methods
        void slash (Character *other) const;
        void move (Character *other);
        ///print override method
        string print() const override;
    };
};
 #endif
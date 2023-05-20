#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;
//Cowboy defualt character
const int BULLETS_AMOUNT = 6;
const int COWBOY_HP = 110;
const int COWBOY_DAMAGE = 10;

namespace ariel {
    class Cowboy: public Character{
        private:
        int bulletsLeft;
        public:
        //Constructor
        Cowboy(const std::string &name, Point location):Character(name, location, COWBOY_HP), bulletsLeft(BULLETS_AMOUNT){}
        //methods
        bool hasboolets() const;
        void reload();
        void shoot(Character *enemey);
        //getter
        int getBullets() const;
        //print override method
        string print() const override;
     };
};
 #endif
#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel {
    class Cowboy: public Character{
        private:
        int bulletsLeft;
        public:
        Cowboy(string name, Point location);
        ~Cowboy() override;
        bool hasboolets();
        void reload();
        void shoot(Character *enemey);
        string print() override;

     };
};
 #endif
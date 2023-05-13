#ifndef TEAM2_HPP
#define TEAM2_HPP
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
namespace ariel{
    class Team2{
        private:
        Character *leader;
        vector<Character*> Warriors;
        public:
         Team2(Character* character);
        //~Team2();
        void add(Character* warrior);
        void attack(Team2* enemies);
        int stillAlive();
        void print();
    };

};
 #endif
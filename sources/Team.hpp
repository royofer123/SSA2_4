#ifndef TEAM_HPP
#define TEAM_HPP
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Point.hpp"
#include "Team2.hpp"
#include <iostream>
namespace ariel{
    class Team{
        private:
        Character *leader;
        vector<Character*> Warriors;
        public:
         Team(Character* character);
       // ~Team();
        void add(Character* warrior);
        void attack(Team* enemies);
        int stillAlive();
        void print();
    };

};

 #endif

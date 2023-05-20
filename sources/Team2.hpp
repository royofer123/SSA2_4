#ifndef TEAM2_HPP
#define TEAM2_HPP
#include "Character.hpp"
#include "Team.hpp"
namespace ariel{
    class Team2: public Team{
        public:
        Team2(Character *leader): Team(leader){}
        //methods
        void attack(Team *enemyTeam) override;
        void print() const override;
    };
};
 #endif
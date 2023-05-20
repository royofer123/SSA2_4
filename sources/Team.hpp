#ifndef TEAM_HPP
#define TEAM_HPP
#include <array>
#include <cstddef>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Point.hpp"
#include <iostream>
using  namespace std;

const int TEAM_MEMBERS=10;
namespace ariel{
    class Team{
    private:
    array <Character*, TEAM_MEMBERS> teamOfWarriors;
    Character *leader;
    size_t warriorsCounter;
    public:
    //constructor
    Team(Character *leader);
    //destructor
    virtual ~Team(){
        for(size_t i=0; i<warriorsCounter;i++){
            delete teamOfWarriors.at(i);
        }
    }
    //methods
    int stillAlive () const;
    void add (Character*);
    static Character* getClosest (Team*, Character*);
    virtual void attack (Team*);
    virtual void print() const;
    //getters
    Character* getLeader () const;
    array <Character*,TEAM_MEMBERS> getWarriors() const;
    size_t getWarriorsCount () const;
    //Tidy required
    Team (Team&) = delete; // Copy Constructor.
    Team (Team&&) noexcept = delete; // Move Constructor.
    Team& operator = (const Team&) = delete; // Copy assignment operator.
    Team& operator = (Team&&) noexcept = delete; // Move assignment operator.  
    //setter
    protected:
    void setWarriorsCounter(size_t);
    void setLeader(Character *leader);
    };

};

 #endif

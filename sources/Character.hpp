#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "Point.hpp"
using namespace std;
namespace ariel{
    class Character{
        private:
            int healthPoints;
            string name;
            Point &location;
        public:
            Character(string Name, Point &location, int healthPoints);
            Character(Character& other);
            Character(Character&& other) noexcept;  // Move constructor
            virtual ~Character();
            Character& operator=(Character&& other) noexcept; //move operator
            virtual bool isAlive();
            virtual double distance(Character* other);
            virtual void hit(int hitting_points);
            virtual string getName();
            virtual Point getLocation();
            virtual string print();
            Character& operator=(const Character& other);

    };

    
};



#endif
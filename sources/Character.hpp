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
            Point location;
            bool isInTeam;
        public:
        //Constructor
            Character(const std::string& name, Point location, int healthPoints)
            :name(name),location(location),healthPoints(healthPoints),isInTeam(false){}
        //Destructor
            virtual ~Character() = default;
        //Getters and setters
            string getName() const;
            Point getLocation() const;
            bool &getIsInteam();
            int getHealhPoints() const;
        //methods
            bool isAlive() const;
            double distance(Character* other) const;
            void hit(int hittingPoints);
        //virtual method--diffrent classes have diffrent prints   
            virtual string print() const=0;

        //Tidy required   
        Character (Character&); // Copy Constructor.
        Character(Character&& ) noexcept; // Move Constructor.
        Character& operator = (const Character&); // Copy assignment operator.
        Character& operator = (Character&&) noexcept; // Move assignment operator.
        protected:
            void setLocation (Point);
            void setHitPoints (int);
   
    }; 
};
#endif
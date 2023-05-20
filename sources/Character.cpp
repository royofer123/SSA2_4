#include "Character.hpp"
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

 bool Character:: isAlive() const{
    return healthPoints>0;
 }
 double Character:: distance(Character* other)const{
    return location.distance(other->location);
 }

 void Character:: hit(int hittingPoints){
   if(hittingPoints<0) throw invalid_argument ("Damage can't be negative");
   if(isAlive()){
       if (hittingPoints >= healthPoints) {
            healthPoints = 0;
        }
            healthPoints -= hittingPoints;  
   }
 }
 string Character::getName() const{
    return this->name;
 }
 Point Character::getLocation()const{
    return this->location;
 }
 int Character :: getHealhPoints () const {
    return healthPoints;
  }
 bool& Character :: getIsInteam () {
    return isInTeam;
 }

 void Character :: setLocation (Point location) { 
   this->location = location;
 }
 void Character :: setHitPoints (int healthPoints) { 
   this->healthPoints = healthPoints;
 }

 

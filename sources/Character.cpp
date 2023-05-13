#include "Character.hpp"
#include <string>
using namespace ariel;
using namespace std;
// Constructor
Character::Character(string name, Point& location, int healthPoints):name(name) , location(location), healthPoints(healthPoints){ }
// Copy Constructor
Character::Character(Character& other)
    : name(other.name), location(other.location), healthPoints(other.healthPoints) {}  
// Destructor   
Character::~Character() {}
  // Implement Character move
Character::Character(Character&& other) noexcept
    : name(std::move(other.name)), location(other.location), healthPoints(other.healthPoints) {
}
Character& Character::operator=(Character&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        location = other.location;
        healthPoints = other.healthPoints;
    }
    return *this;
}
 bool Character:: isAlive(){
    return this->healthPoints>0;
 }
 double Character:: distance(Character* other){
    return this->location.distance(other->location);
 }

 void Character:: hit(int hitting_points){
    healthPoints-=hitting_points;
    if( this->healthPoints<0) this->healthPoints=0;
 }
 string Character::getName(){
    return this->name;
 }
 Point Character::getLocation(){
    return this->location;
 }
 string Character::print(){
    string info = "Name: " + this->name + "\n";
    info += "Health Points: " + to_string(this->healthPoints) + "\n";
    info += "Location: (" + to_string(this->location.getX()) + ", " + to_string(this->location.getY()) + ")";
    return info;
 }

 Character& Character::operator=(const Character& other){
    if(this==&other) return *this;
    this->name=other.name;
    this->location=other.location;
    this->healthPoints=other.healthPoints;
    return *this;
 }

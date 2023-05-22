#include "Ninja.hpp"
#include "Point.hpp"
#include <stdexcept>
using namespace ariel;

void Ninja::move(Character* other) {
    if(other==nullptr) throw invalid_argument ("Enemey cant be null!");
    setLocation(Point::moveTowards(getLocation(), other->getLocation(), speed));
    
}
void Ninja::slash(Character* other) const{
    if(other==nullptr) throw invalid_argument ("Enemey cant be null!");
    if(other->isAlive()==false) throw runtime_error ("Can't slash a dead enemey");
    if(!isAlive()) throw runtime_error ("Can't slashing im in heaven");
    if(this==other) throw runtime_error ("I can't slash myself, im scared");
    if (getLocation().distance(other -> getLocation()) < 1) {
        other -> hit (NINJA_DMG);
    }   
}

string Ninja::print() const {
    string info;
    info="~~~~Character name:(Ninja) " + getName() + " ~~~~\n";
    if(isAlive()){
         info += "[Hit Points: " + to_string(getHealhPoints()) + "]\n";
    }
    info += "[Location: " + getLocation().toString() + "]\n";
    return info;
}

int Ninja::getSpeed() const {
    return this->speed;
}

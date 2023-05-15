#include "Ninja.hpp"

using namespace ariel;



void Ninja::move(Character* other) {
    
}

void Ninja::slash(Character* other) {
    
}

string Ninja::print() {

    return "";
}

int Ninja::getSpeed() {
    return this->speed;
}

OldNinja::OldNinja(string name, Point location) : Ninja((name), 150,location,  8) {}

YoungNinja::YoungNinja(string name, Point location) : Ninja((name), 100,location,  14) {}

TrainedNinja::TrainedNinja(string name, Point location) : Ninja((name),120, location, 12) {}


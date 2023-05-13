#include "Ninja.hpp"

using namespace ariel;

//Ninja::~Ninja() {}

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

OldNinja::OldNinja(string&& name, Point location) : Ninja(std::move(name), 150, location, 8) {}

YountNinja::YountNinja(string&& name, Point location) : Ninja(std::move(name), 100, location, 14) {}

TrainedNinja::TrainedNinja(string&& name, Point location) : Ninja(std::move(name), 120, location, 12) {}


#include "Cowboy.hpp"

using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), bulletsLeft(6) {

}

bool Cowboy::hasboolets() {
    return bulletsLeft > 0;
}

void Cowboy::reload() {
   
}

void Cowboy::shoot(Character* enemy) {

}

string Cowboy::print() {
    return "";
}

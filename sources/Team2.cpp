#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character* character) : leader(character) {

}

// Team2::~Team2() {
//     delete leader;
//     for (Character* warrior : Warriors) {
//         delete warrior;
//     }}


void Team2::add(Character* warrior) {
    Warriors.push_back(warrior);
}

void Team2::attack(Team2* enemies) {
}

int Team2::stillAlive() {
    return 0;
}

void Team2::print() {
}

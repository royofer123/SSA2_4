#include "Team.hpp"

using namespace ariel;

Team::Team(Character* character) : leader(character) {

}

// Team::~Team() {
//     delete leader;
//     for (Character* warrior : Warriors) {
//         delete warrior;
//     }
// }

void Team::add(Character* warrior) {
    Warriors.push_back(warrior);
}

void Team::attack(Team* enemies) {
}

int Team::stillAlive() {
    return 0;
}

void Team::print() {
}

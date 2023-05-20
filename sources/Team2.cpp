#include "Team2.hpp"
#include <cstddef>

using namespace ariel;

void Team2::attack(Team* enemyTeam) {
    // Check if the enemy team is null
    if (enemyTeam == nullptr) throw invalid_argument("Enemy team can't be null!\n");
    
    // Check if the team is trying to attack itself
    if (this == enemyTeam) throw runtime_error("Team can't attack itself!\n");
    
    // Check if both teams have at least one member alive
    if (stillAlive() == 0 || enemyTeam->stillAlive() == 0) throw runtime_error("Both teams need to have at least one member alive\n");
    
    // Check if the leader of the attacking team is alive
    if (!getLeader()->isAlive()) setLeader(getClosest(this, getLeader()));
    
    // Initialize pointers for Cowboy and Ninja characters
    Cowboy* pointedCowboy;
    Ninja* pointedNinja;
    
    // Get the closest alive character from the enemy team relative to the attacking team's leader
    Character* victim = getClosest(enemyTeam, getLeader());
    
    // Attacking the enemy team
    for (size_t i = 0; i < getWarriorsCount() && victim->isAlive(); i++) {
        // Get a reference to the current warrior
        auto& tempWarrior = *getWarriors().at(i);
        
        // Check if the warrior is of type Cowboy
        if (typeid(tempWarrior) == typeid(Cowboy)) {
            pointedCowboy = dynamic_cast<Cowboy*>(getWarriors().at(i));
            if (pointedCowboy->isAlive()) {
                if (pointedCowboy->hasboolets()) {
                    // Shoot the victim if the Cowboy has bullets
                    pointedCowboy->shoot(victim);
                    if (!victim->isAlive()) {
                        // If the victim is killed, find the next closest alive character from the enemy team
                        victim = getClosest(enemyTeam, getLeader());
                    }
                } else {
                    // Reload the Cowboy if there are no bullets
                    pointedCowboy->reload();
                }
            }
        } else {
            // The warrior is of type Ninja
            pointedNinja = dynamic_cast<Ninja*>(getWarriors().at(i));
            if (pointedNinja->isAlive()) {
                if (pointedNinja->getLocation().distance(victim->getLocation()) <= 1) {
                    // Slash the victim if the Ninja is within range
                    pointedNinja->slash(victim);
                    if (!victim->isAlive()) {
                        // If the victim is killed, find the next closest alive character from the enemy team
                        victim = getClosest(enemyTeam, getLeader());
                    }
                } else {
                    // Move the Ninja towards the victim if not within range
                    pointedNinja->move(victim);
                }
            }
        }
    }
}
void Team2 ::print () const {
    for (size_t i = 0; i < getWarriorsCount(); i++) {
        cout << getWarriors().at(i) -> print() << endl;
    }
}
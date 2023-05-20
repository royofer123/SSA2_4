#include "Team.hpp"
#include "Character.hpp"
#include <cstddef>
#include <stdexcept>
#include <limits>
using namespace std;
using namespace ariel;
Team :: Team (Character *leader) {
    if(leader->getIsInteam()) throw runtime_error ("Leader is allready in a team!");
    if(leader==nullptr) throw invalid_argument ("Leader can't be null");
    if(!leader->isAlive()) throw invalid_argument ("Dead man can't lead an army");
    warriorsCounter=0;
    teamOfWarriors.at(warriorsCounter++)=leader;
    this->leader=leader;
    leader->getIsInteam()=true;
}
int Team::stillAlive() const{
    int count= 0;
    for(size_t i=0; i<warriorsCounter;i++){
        if(teamOfWarriors.at(i)->isAlive()) count++;
    }
    return count;
}
void Team::add(Character *member){
    if(member->getIsInteam()) throw runtime_error ("member is allready in a team!");
    if(member==nullptr) throw invalid_argument ("member can't be null");
    if(!member->isAlive()) throw invalid_argument ("Dead man can't join an army");
    if(warriorsCounter==TEAM_MEMBERS) throw runtime_error ("Army is allready full! can't add more members");
    teamOfWarriors.at(warriorsCounter++)=member;
    member->getIsInteam()=true;
}
Character* Team :: getClosest (Team* team, Character* leader) {
    Character* warrior = team -> teamOfWarriors.at(0);
    double minDist = numeric_limits <double> :: max();
    double dist = 0;
    for (size_t i = 0; i < team -> warriorsCounter; i++) {
        dist = leader -> distance(team -> teamOfWarriors.at(i));
        if (team -> teamOfWarriors.at(i) -> isAlive() && dist < minDist) {
            minDist = dist;
            warrior = team -> teamOfWarriors.at(i);
        }
    }
    return warrior;
}
void Team::attack(Team* enemyTeam) {
    // Attack the enemy team

    // Check if the enemy team is null
    if (enemyTeam == nullptr) {
        throw invalid_argument("Enemy team can't be null!\n");
    }

    // Check if the team is trying to attack itself
    if (this == enemyTeam) {
        throw runtime_error("Team can't attack itself!\n");
    }

    // Check if both teams have at least one member alive
    if (stillAlive() == 0 || enemyTeam->stillAlive() == 0) {
        throw runtime_error("Both teams need to have at least one member alive\n");
    }

    // Check if the leader of the attacking team is alive
    if (!leader->isAlive()) {
        leader = getClosest(this, leader);
    }

    Cowboy* pointedCowboy;
    Ninja* pointedNinja;

    // Get the closest alive character from the enemy team relative to the attacking team's leader
    Character* victim = getClosest(enemyTeam, leader);

    // Iterate through the warriors of the attacking team and attack the enemy team
    for (size_t i = 0; i < warriorsCounter && victim->isAlive(); i++) {
        auto& tempWarrior = *teamOfWarriors.at(i);

        // Attack using cowboys
        if (typeid(tempWarrior) == typeid(Cowboy)) {
            pointedCowboy = dynamic_cast<Cowboy*>(teamOfWarriors.at(i));
            if (pointedCowboy->isAlive()) {
                if (pointedCowboy->hasboolets()) {
                    // Shoot the victim if the cowboy has bullets
                    pointedCowboy->shoot(victim);
                    if (!victim->isAlive()) {
                        // If the victim is killed, find the next closest alive character from the enemy team
                        victim = getClosest(enemyTeam, leader);
                    }
                } else {
                    // Reload the cowboy if there are no bullets
                    pointedCowboy->reload();
                }
            }
        }
    }

    // Iterate through the warriors of the attacking team and attack the enemy team
    for (size_t i = 0; i < warriorsCounter && victim->isAlive(); i++) {
        auto& tempWarrior = *teamOfWarriors.at(i);

        // Attack using ninjas
        if (typeid(tempWarrior) != typeid(Cowboy)) {
            pointedNinja = dynamic_cast<Ninja*>(teamOfWarriors.at(i));
            if (pointedNinja->isAlive()) {
                if (pointedNinja->getLocation().distance(victim->getLocation()) <= 1) {
                    // Slash the victim if the ninja is within range
                    pointedNinja->slash(victim);
                    if (!victim->isAlive()) {
                        // If the victim is killed, find the next closest alive character from the enemy team
                        victim = getClosest(enemyTeam, leader);
                    }
                } else {
                    // Move the ninja towards the victim if not within range
                    pointedNinja->move(victim);
                }
            }
        }
    }
}
void Team :: print() const {
    // Iterate first over the cowboys.
    for (size_t i = 0; i < warriorsCounter; i++) {
        auto &temp_warrior = *teamOfWarriors.at(i);
        if (typeid (temp_warrior) == typeid (Cowboy)) {
            cout << teamOfWarriors.at(i) -> print() << endl;
        }
    }
    // Iterate now over the ninjas.
    for (size_t i = 0; i < warriorsCounter; i++) {
        auto &temp_warrior = *teamOfWarriors.at(i);
        if (typeid (temp_warrior) != typeid (Cowboy)) {
            cout << teamOfWarriors.at(i) -> print() << endl;
        }
    }
}

array <Character*, TEAM_MEMBERS> Team :: getWarriors() const {
     return teamOfWarriors;
      }
size_t Team :: getWarriorsCount () const {
     return warriorsCounter;
      }
Character* Team :: getLeader () const { 
    return leader;
     }
void Team :: setWarriorsCounter (size_t warriorsCount) { 
    warriorsCounter = warriorsCount;
     }
void Team :: setLeader (Character* leader) { 
    this->leader = leader;
     }

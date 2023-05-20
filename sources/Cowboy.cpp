#include "Cowboy.hpp"
#include <stdexcept>
using namespace std;
using namespace ariel;
bool Cowboy::hasboolets() const{
    return bulletsLeft > 0;
}
void Cowboy::reload() {
    if(!isAlive()){
    throw runtime_error("Im dead! I cant reload!");
    }
    bulletsLeft=BULLETS_AMOUNT;
}
void Cowboy::shoot(Character* enemy) {
    if(enemy==nullptr) throw invalid_argument ("Enemey cant be null!");
    if(enemy->isAlive()==false) throw runtime_error ("Can't shoot a dead enemey");
    if(!isAlive()) throw runtime_error ("Can't shoot im in heaven");
    if(this==enemy) throw runtime_error ("I can't shoot myself, im scared");
    if(bulletsLeft>0){
        enemy->hit(COWBOY_DAMAGE);
        bulletsLeft-=1;
    }
}
string Cowboy::print() const {
    string info;
    info="~~~~Character name:(Cowboy) " + getName() + " ~~~~\n";
    if(isAlive()){
         info += "[Hit Points: " + to_string(getHealhPoints()) + "]\n";
    }
    info += "[Location: " + getLocation().toString() + "]\n";
    return info;
}
int Cowboy::getBullets () const {
    return this->bulletsLeft;
}
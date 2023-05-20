#ifndef OLDNINJA_H
#define OLDNINJA_H
#include "Ninja.hpp"
#include "Character.hpp"
const int OLD_NINJA_SPEED = 8;
const int OLD_NINJA_HP = 150;

namespace ariel {
    class OldNinja : public Ninja {

    public:
        // Constructors.
        OldNinja (const std::string &name, Point location) :
            Ninja(name, location,OLD_NINJA_HP,  OLD_NINJA_SPEED) {}
    };
}

#endif 
#ifndef YOUNGNINJA_H
#define YOUNGNINJA_H
#include "Ninja.hpp"
#include "Character.hpp"
const int YOUNG_NINJA_SPEED = 14;
const int YOUNG_NINJA_HP = 100;

namespace ariel {
    class YoungNinja : public Ninja {

    public:
        // Constructors.
        YoungNinja (string name, Point location) :
            Ninja((name), YOUNG_NINJA_HP,location,  YOUNG_NINJA_SPEED) {}
    };
}

#endif 
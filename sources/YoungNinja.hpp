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
        YoungNinja (const std::string &name, Point location) :
            Ninja(name, location,YOUNG_NINJA_HP,  YOUNG_NINJA_SPEED) {}
    };
    };
#endif 
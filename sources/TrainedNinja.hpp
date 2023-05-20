#ifndef TRAINEDNINJA_H
#define TRAINEDNINJA_H
#include "Ninja.hpp"
#include "Character.hpp"
const int TRAINED_NINJA_SPEED = 12;
const int TRAINED_NINJA_HP = 120;

namespace ariel {
    class TrainedNinja : public Ninja {

    public:
        // Constructors.
        TrainedNinja (const std::string &name, Point location) :
            Ninja(name, location,TRAINED_NINJA_HP,  TRAINED_NINJA_SPEED) {}
    };
   };
#endif 
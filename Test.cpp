#include <iostream>
#include <cassert>
#include <sstream>
#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test Character class") {
    Point location1(1.0, 2.0);
    Point location2(3.0, 4.0);
    Character character1("Alice", location1, 100);
    Character character2("Bob", location2, 120);

    CHECK(character1.isAlive());
    CHECK(character2.isAlive());
    CHECK(character1.distance(&character2) == character2.distance(&character1));
    character1.hit(30);
    character2.hit(50);
    CHECK(character1.isAlive());
    CHECK(character2.isAlive());
    CHECK(character1.getName() == "Alice");
    CHECK(character2.getName() == "Bob");
    CHECK(character1.getLocation().getX() == 1.0);
    CHECK(character1.getLocation().getY() == 2.0);
    CHECK(character2.getLocation().getX() == 3.0);
    CHECK(character2.getLocation().getY() == 4.0);
    CHECK(character1.print() == "Character: Alice, Health: 70");
    CHECK(character2.print() == "Character: Bob, Health: 70");

    Character character3(character1);
    CHECK(character3.isAlive());
    CHECK(character3.getName() == "Alice");
    CHECK(character3.getLocation().getX() == 1.0);
    CHECK(character3.getLocation().getY() == 2.0);
    CHECK(character3.print() == "Character: Alice, Health: 70");

    character3 = character2;
    CHECK(character3.isAlive());
    CHECK(character3.getName() == "Bob");
    CHECK(character3.getLocation().getX() == 3.0);
    CHECK(character3.getLocation().getY() == 4.0);
    CHECK(character3.print() == "Character: Bob, Health: 70");
}

TEST_CASE("Test Cowboy class") {
    Point location(1.0, 2.0);
    Cowboy cowboy("John", location);

    CHECK(!cowboy.hasboolets());
    cowboy.reload();
    CHECK(cowboy.hasboolets());
    CHECK(cowboy.print() == "Character: John (Cowboy), Health: 100, Bullets: 6");

    Point enemyLocation(3.0, 4.0);
    Character enemy("Enemy", enemyLocation, 100);
    cowboy.shoot(&enemy);
    CHECK(cowboy.print() == "Character: John (Cowboy), Health: 100, Bullets: 5");
    CHECK(enemy.print() == "Character: Enemy, Health: 90");
}

TEST_CASE("Test Team class") {
    Point location1(1.0, 2.0);
    Point location2(3.0, 4.0);
    Cowboy *cowboy1 = new Cowboy("John", location1);
    Cowboy *cowboy2 = new Cowboy("Mike", location2);
    Team team(cowboy1);
    team.add(cowboy2);

    CHECK(team.stillAlive() == 2);
    team.attack(nullptr);
    CHECK(team.stillAlive() == 2);
    }
    TEST_CASE("Test Ninja class") {
    Point location(1.0, 2.0);
    Ninja ninja("Hiro", 120, location, 10);

    CHECK(ninja.isAlive());
    CHECK(ninja.getSpeed() == 10);
    CHECK(ninja.print() == "Character: Hiro (Ninja), Health: 120, Speed: 10");

    Point enemyLocation(3.0, 4.0);
    Character enemy("Enemy", enemyLocation, 100);
    ninja.move(&enemy);
    CHECK(ninja.getLocation().getX() == 3.0);
    CHECK(ninja.getLocation().getY() == 4.0);

    ninja.slash(&enemy);
    CHECK(enemy.print() == "Character: Enemy, Health: 90");
}

TEST_CASE("Test Team2 class") {
    Point location1(1.0, 2.0);
    Point location2(3.0, 4.0);
    Ninja *ninja1 = new Ninja("Hiro", 120, location1, 10);
    Ninja *ninja2 = new Ninja("Kai", 100, location2, 8);
    Team2 team(ninja1);
    team.add(ninja2);

    CHECK(team.stillAlive() == 2);
    team.attack(nullptr);
    CHECK(team.stillAlive() == 2);
}



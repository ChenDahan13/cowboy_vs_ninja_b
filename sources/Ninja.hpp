#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
#include "Character.hpp"
using namespace std;
using namespace ariel;

const int DEFAULT_SPEED = 20;

class Ninja: public Character {
    
    int speed;

    public:
        Ninja(string name = "Chen", Point position = Point(0,0), int points = DEFAULT_POINTS, int speed = DEFAULT_SPEED);
        ~Ninja() override = default;
        Ninja(const Ninja& other) = default;
        Ninja& operator=(const Ninja& other) = default;
        Ninja(Ninja&& other) noexcept = default;
        Ninja& operator=(Ninja&& other) noexcept = default;

        void move(const Character* enemy);
        void slash(Character* enemy);

};
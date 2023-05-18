#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
#include "Character.hpp"
using namespace std;
using namespace ariel;


class Cowboy: public Character {

    int bullets;

    public:
        Cowboy(string name = "Chen", Point position = Point(0,0));
        ~Cowboy() override = default;
        Cowboy(const Cowboy& other) = default;
        Cowboy& operator=(const Cowboy& other) = default;
        Cowboy(Cowboy&& other) noexcept = default;
        Cowboy& operator=(Cowboy&& other) noexcept = default;

        void shoot(Character* enemy);
        bool hasboolets();
        void reload();

};
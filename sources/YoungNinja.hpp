#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;
using namespace ariel;


class YoungNinja: public Ninja {

    public:
        YoungNinja(string name = "Chen", Point position = Point(0,0));
        ~YoungNinja() override = default;
        YoungNinja(const YoungNinja& other) = default;
        YoungNinja& operator=(const YoungNinja& other) = default;
        YoungNinja(YoungNinja&& other) noexcept = default;
        YoungNinja& operator=(YoungNinja&& other) noexcept = default;

};
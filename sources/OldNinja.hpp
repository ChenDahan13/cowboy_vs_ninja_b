#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;
using namespace ariel;


class OldNinja: public Ninja {

    public:
        OldNinja(string name = "Chen", Point position = Point(0,0));
        ~OldNinja() override = default;
        OldNinja(const OldNinja& other) = default;
        OldNinja& operator=(const OldNinja& other) = default;
        OldNinja(OldNinja&& other) noexcept = default;
        OldNinja& operator=(OldNinja&& other) noexcept = default;
        
};
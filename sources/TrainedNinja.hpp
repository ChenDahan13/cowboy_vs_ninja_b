#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;
using namespace ariel;


class TrainedNinja: public Ninja {

    public:
        TrainedNinja(string name = "Chen", Point position = Point(0,0));
        ~TrainedNinja() override = default;
        TrainedNinja(const TrainedNinja& other) = default;
        TrainedNinja& operator=(const TrainedNinja& other) = default;
        TrainedNinja(TrainedNinja&& other) noexcept = default;
        TrainedNinja& operator=(TrainedNinja&& other) noexcept = default;
        
};
#pragma once
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"

using namespace ariel;
using namespace std;


class Team2: public Team{
        
    public:
        Team2(Character* character);
        void add(Character* character) override; 
        void attack(Team* enemies) override;   
        void print() override;
        ~Team2() override;     

        Team2() = default;
        Team2(const Team2& other) = default;
        Team2 &operator=(const Team2& other) = default;
        Team2(Team2&& other) noexcept = default;
        Team2 &operator=(Team2&& other) noexcept = default;
        
};
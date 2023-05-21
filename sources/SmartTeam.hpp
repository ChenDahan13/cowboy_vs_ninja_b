#pragma once
#include <vector>
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

class SmartTeam: public Team {
    
    Character* closest_enemy_to_ninja(Character* ninja, Team* enemeis);
    Character* smart_find_victim(Team* enemies);

    public:
        SmartTeam(Character* character);
        ~SmartTeam() override;;
        void attack(Team* enemies) override;

        SmartTeam() = default;
        SmartTeam(const SmartTeam& other) = default;
        SmartTeam &operator=(const SmartTeam& other) = default;
        SmartTeam(SmartTeam&& other) noexcept = default;
        SmartTeam &operator=(SmartTeam&& other) noexcept = default;

};  
#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"

using namespace ariel;
using namespace std;


class Team {

    friend class Team2;
    
    public:
    
        vector<Character*> team; 
        Character* leader; // Leader of the team
        
        void copy_func(const Team& other);
        Character* closest_team_member();
        Character* closest_victim(Team* other);
        Team(Character* character);
        Team(const Team& other);
        Team() = default;
        Team& operator=(const Team& other);
        Team(Team&& other) = default;
        Team& operator=(Team&& other) = default;
        virtual ~Team();

        virtual void add(Character* character);
        virtual void attack(Team* enemies);
        int stillAlive();
        virtual void print();

};
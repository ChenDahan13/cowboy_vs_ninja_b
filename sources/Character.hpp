#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
using namespace std;
using namespace ariel;

const int DEFAULT_POINTS = 50;

class Character {
    
    Point position;
    int points;
    string name;
    int type; // 0 for cowboys, 1 for ninjas
    
    public:
        Character(string name = "Chen", Point position = Point(0,0), int points = DEFAULT_POINTS, int type = 0);
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        Character(Character&& other) = default;
        Character& operator=(Character&& other) = default;

        bool isAlive();
        double distance(const Character* other);
        void hit(int points);
        string getName();
        Point getLocation() const;
        void setLocation(Point other);
        virtual string print();
        int getType();
        int getPoints();

};
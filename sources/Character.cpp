#include "Character.hpp"

using namespace ariel;
using namespace std;


/*--------------- Character Class ---------------*/ 
Character::Character(string name, Point position, int points, int type): name(name), position(position), points(points), type(type), isInTeam(false) {}
Character::Character(const Character& other): name(other.name), position(other.position), points(other.points), type(other.type) , isInTeam(false) {}
Character::~Character() {}

Character& Character::operator=(const Character& other) {
    if(this == &other) return *this;
    this->name = other.name;
    this->position.setX(other.position.getX());
    this->position.setY(other.position.getY());
    this->points = other.points;
    this->type = other.type;
    return *this;
}

bool Character::isAlive() {
    return (this->points > 0) ? true : false;
}

// Returns if the character already in a team
bool Character::isAlreadyInTeam() {
    return isInTeam;
}

void Character::setIsInTeam(bool b) {
    this->isInTeam = b;
}

// Calculates distance between this Character to another
double Character::distance(const Character* other) {
    return this->position.distance(other->position);
}

// This character has been hit
void Character::hit(int points) {
    if(points < 0) {
        throw invalid_argument("The points to hit can't be zero or negative");
    }
    this->points = this->points - points;
    if(this->points < 0) { // Can't be negative health
        this->points = 0;
    }
}

string Character::getName() {
    return this->name;
}

Point Character::getLocation() const {
    return this->position;
}

void Character::setLocation(Point p) {
    this->position = p;
}

int Character::getType() {
    return type; // Returns 0 for cowboys, 1 for ninjas
}

int Character::getPoints() {
    return points;
}

string Character::print() {
    string str = "";
    if(!this->isAlive()) {
        if(this->type == 0) { // Cowboy
            str += "C (" + this->name + ") position: " + this->position.print(); 
        } else if(this->type == 1) { // Ninja
            str += "N (" + this->name + ") position: " + this->position.print(); 
        }
    } else {
        if(this->type == 0) { // Cowboy
            str += "C " + this->name + " points: " + to_string(this->points) + " position: " + this->position.print(); 
        } else if(this->type == 1) { // Ninja
            str += "N " + this->name + " points: " + to_string(this->points) + " position: " + this->position.print(); 
        }
    }
    return str;
}
/*----------------------------------------------------*/
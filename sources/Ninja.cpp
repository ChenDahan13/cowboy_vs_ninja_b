#include "Ninja.hpp"


/*--------------- Ninja Class ---------------*/
Ninja::Ninja(string name, Point position, int points, int speed): Character(name, position, points, 1), speed(speed) {}

// Changes the position of the character according to its speed
void Ninja::move(const Character* enemy) {
    Point src = this->getLocation();
    Point dest = enemy->getLocation();
    Point newPosition = Point::moveTowards(src, dest, this->speed);
    setLocation(newPosition);
}

// Hits the enemy 
void Ninja::slash(Character* enemy) {
    double dist = this->distance(enemy);
    if(dist < 1.0 && this->isAlive()) {
        enemy->hit(40);
    }
}
/*-------------------------------------------*/
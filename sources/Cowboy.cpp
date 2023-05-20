#include "Cowboy.hpp"

/*--------------- Cowboy Class ---------------*/
Cowboy::Cowboy(string name, Point position): Character(name, position, 110, 0), bullets(6) {}

// This cowboy will damage the enemy
void Cowboy::shoot(Character* enemy) {

    if(this == enemy)
        throw runtime_error("Cowboy can't shoot himself");
    
    if(!enemy->isAlive()) 
        throw runtime_error("Cowboy can't shoot dead enemy");
    
    if(!this->isAlive()) 
        throw runtime_error("Dead cowboy can't shoot anybody");
    
    if(this->isAlive() && this->hasboolets()) {
        enemy->hit(10);
        this->bullets = this->bullets - 1;
    }
}

bool Cowboy::hasboolets() {
    return (this->bullets > 0) ? true : false;
}

void Cowboy::reload() {
    if(!this->isAlive())
        throw runtime_error("Dead cowboy can't reload");
    
    this->bullets = this->bullets + 6;
    if(this->bullets > 6)
        this->bullets = 6;
}
/*---------------------------------------------*/
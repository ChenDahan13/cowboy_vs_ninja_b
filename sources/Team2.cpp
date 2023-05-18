#include "Team2.hpp"


/*----------- Team2 Class ------------*/
Team2::Team2(Character* character): Team(character) {}

Team2::~Team2() {
    for(std::vector<Character*>::size_type i = 0; i < this->team.size() ; i++) {
        delete this->team[i];
    }
}

// Adds members to the team. Until 10 members
void Team2::add(Character* character) {
    if(this->team.size() < 10) {
        this->team.push_back(character);
    }
}

void Team2::attack(Team* enemies) {
    if(!enemies->stillAlive()) // Check first if the enemy team alive
        return;
    
    if(!leader->isAlive()) { // If leader is dead, replace him to new one that is the closest to him
        leader = closest_team_member();
    }

    Character* victim = closest_victim(enemies);
    if(victim == nullptr) 
        return;

    
    for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
        if(!victim->isAlive()) { // If the victim is dead, choose a new one
            victim = closest_victim(enemies);
            if(victim == nullptr) // No enemies alive
                return;
        }
        if(this->team[i]->isAlive() && this->team[i]->getType() == 0) { // Cowboys
            Cowboy* c = dynamic_cast<Cowboy*>(this->team[i]);
            if(c->hasboolets()) {
                c->shoot(victim);
            } else {
                c->reload();
            }
        } else if(this->team[i]->isAlive() && this->team[i]->getType() == 1) { // Ninjas
            Ninja *n = dynamic_cast<Ninja*>(this->team[i]);
            if(n->distance(victim) <= 1.0) { // Attack only if close to victim under 1 meter
                n->slash(victim);
            } else {
                n->move(victim);
            }
        }
    }
}

void Team2::print() {
    if(!this->team.empty()) {
        for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
                cout << this->team[i]->print() << endl; 
        }
    }      
}
/*------------------------------------*/
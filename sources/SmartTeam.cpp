#include "SmartTeam.hpp"

/*----------- SmartTeam Class -----------*/
SmartTeam::SmartTeam(Character* character): Team(character) {}

SmartTeam::~SmartTeam() {
    for(std::vector<Character*>::size_type i = 0; i < this->team.size() ; i++) {
        delete this->team[i];
    }
    this->team.clear();
    this->leader = nullptr;
}

// Finds the closest enemy to member type ninja
Character* SmartTeam::closest_enemy_to_ninja(Character* member, Team* enemies) {
    Character* closest = nullptr;
    double min_distance = numeric_limits<double>::max();
    for(std::vector<Character*>::size_type i = 0; i < enemies->team.size(); i++) {
        if(enemies->team[i]->isAlive()) { // If the enemy is alive
            double distance = member->distance(enemies->team[i]); // Calculate the distance between the member and the enemy
            if(distance < min_distance) {
                min_distance = distance;
                closest = enemies->team[i];
            }
        }
    }
    return closest;
}

// Finds the victim that is the closest to the ninjas in the team
Character* SmartTeam::smart_find_victim(Team* enemies) {
    vector<Character*> optional_victims;
    
    // Creates a vector of optional victims 
    // that are the closest enemies to the ninjas in the team
    for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
        if(this->team[i]->isAlive() && this->team[i]->getType() == 1) { // If the member is alive and type ninja
            Character* closest_enemy = closest_enemy_to_ninja(this->team[i], enemies);
            if(closest_enemy != nullptr) {
                optional_victims.push_back(closest_enemy);
            }
        }
    }

    int maxcount = 0;
    Character* victim = nullptr;
    
    // Finds the victim that is the most common in the vector
    for(std::vector<Character*>::size_type i = 0; i < optional_victims.size(); i++) {
        int count = 0;
        for(std::vector<Character*>::size_type j = 0; j < optional_victims.size(); j++) {
            if(optional_victims[i] == optional_victims[j]) {
                count++;
            }
        }
        if(count > maxcount) {
            maxcount = count;
            victim = optional_victims[i];
        }
    }
    
    optional_victims.clear();
    return victim;
}

void SmartTeam::attack(Team* enemies) {
    
        if(enemies == nullptr) // Checks the argument is ok
            throw invalid_argument("Attack() function can't get as an argument nullptr");
    
        if(enemies->stillAlive() == 0) // Checks first if the enemy team alive
            throw runtime_error("Attacking dead team isn't possible");
        
        if(!leader->isAlive()) { // If leader is dead, replace him to new one that is the closest to him
            leader = closest_team_member();
        }
    
        Character* victim = smart_find_victim(enemies);
        if(victim == nullptr) 
            return;
    
        
        for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
            if(!victim->isAlive()) { // If the victim is dead, choose a new one
                victim = smart_find_victim(enemies);
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
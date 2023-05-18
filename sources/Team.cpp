#include "Team.hpp"

/*----------- Team Class ------------*/
Team::Team(Character* character): leader(character) {
    this->team.push_back(character);
}

// Copies other team to this object team
void Team::copy_func(const Team& other) {
    
    if(!this->team.empty()) { // The team isn't empty
        // Free all the memory
        for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
            delete this->team[i];
        }
        this->team.clear(); // Moves all the elements inside
    }

    for (std::vector<Character*>::size_type i = 0; i < other.team.size(); i++){
        this->team.push_back(other.team[i]); // Puts the other team members inside 
    }
    
}


// Finds the closest team member to the leader of the team
Character* Team::closest_team_member() {
    double minDest = std::numeric_limits<double>::max();
    Character *member = nullptr;
    for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
        if(this->team[i]->isAlive()) {
            double dest = leader->distance(this->team[i]);
            if(dest < minDest) {
                minDest = dest;
                member = this->team[i];
            }
        }
    }
    return member;
}


// Finds the closest member to the leader of the attack team from the enemy team 
Character* Team::closest_victim(Team* other) {
    double minDest = std::numeric_limits<double>::max();
    Character *member = nullptr;
    for(std::vector<Character*>::size_type i = 0; i < other->team.size(); i++) {
        if(other->team[i]->isAlive()) {
            double dest = leader->distance(other->team[i]);
            if(dest < minDest) {
                minDest = dest;
                member = other->team[i];
            }
        }
    }
    return member;
}

Team::Team(const Team& other): leader(other.leader){
    copy_func(other);
}

Team& Team::operator=(const Team& other) {
    copy_func(other);
    this->leader = other.leader;
    return *this;
}

Team::~Team() {
    for(std::vector<Character*>::size_type i = 0; i < this->team.size() ; i++) {
        delete this->team[i];
    }
}

// Adds members to the team. Until 10 members
void Team::add(Character* character) {
    if(this->team.size() < 10) {
        this->team.push_back(character);
    }
}

void Team::attack(Team* enemies) {
    if(!enemies->stillAlive()) // Check first if the enemy team alive
        return;
    
    if(!leader->isAlive()) { // If leader is dead, replace him to new one that is the closest to him
        leader = closest_team_member();
        if(leader == nullptr)
            return;
    }

    Character* victim = closest_victim(enemies);
    if(victim == nullptr) 
        return;

    // Cowboys attack first
    for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
        if(!victim->isAlive()) { // If the victim is dead, choose a new one
            victim = closest_victim(enemies);
            if(victim == nullptr) // No enemies alive
                return;
        }
        if(this->team[i]->isAlive() && this->team[i]->getType() == 0) { // Cowboys first
            Cowboy* c = dynamic_cast<Cowboy*>(this->team[i]);
            if(c->hasboolets()) {
                c->shoot(victim);
            } else {
                c->reload();
            }
        }
    }

    // Ninjas attack after
    for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
        if(!victim->isAlive()) { // If the victim is dead, choose a new one
            victim = closest_victim(enemies);
            if(victim == nullptr) // No enemies alive
                return;
        }
        if(this->team[i]->isAlive() && this->team[i]->getType() == 1) { // Ninjas second
            Ninja *n = dynamic_cast<Ninja*>(this->team[i]);
            if(n->distance(victim) <= 1.0) { // Attack only if close to victim under 1 meter
                n->slash(victim);
            } else {
                n->move(victim);
            }
        }
    }

    
}

// Counts all the members that alive in this team
int Team::stillAlive() {
    int aliveMembers = 0;
    for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
        if(this->team[i]->isAlive()) aliveMembers++; // Counts all the members 
    }
    return aliveMembers;
}

// prints the team members details
void Team::print() {
    if(!this->team.empty()) {
        for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
           if(team[i]->getType() == 0) {
                cout << this->team[i]->print() << endl; // Cowboys first
           }
        }
        for(std::vector<Character*>::size_type i = 0; i < this->team.size(); i++) {
           if(team[i]->getType() == 1) {
                cout << this->team[i]->print() << endl; // Ninjas second
           }
        }
    }
}
/*------------------------------------*/
#include "Point.hpp"
#include <cmath>
using namespace ariel;
using namespace std;

Point::Point(double x, double y): x(x), y(y) {}
Point::Point(const Point& other): x(other.x), y(other.y) {}
Point::~Point() {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

Point& Point::operator=(const Point& other) {
    if(this == &other) return *this;
    this->x = other.x;
    this->y = other.y;
    return *this;
}

double Point::distance(const Point& other) const{
    return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2) * 1.0);
}

string Point::print() {
    string str = "(" + to_string(this->x) + "," + to_string(this->y) + ")";
    return str;
}

/* Calculate the nearest point to the destination point
   given distance from the source point */
Point Point::moveTowards(const Point& source, const Point& dest, double distance) {
    if(distance < 0) {
        throw invalid_argument("There is no such a thing as negative distance");   
    }
    double distance_of_2_points = source.distance(dest);
    if(distance >= distance_of_2_points) {
        return dest;
    }
    double t = distance / distance_of_2_points;
    double newX = (1 - t)*source.x + t*dest.x;
    double newY = (1 - t)*source.y + t*dest.y;
    return Point(newX,newY);
}


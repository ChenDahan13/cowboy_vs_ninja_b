#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel {

    class Point {
        
        double x;
        double y;

        public:
            Point(double xcor = 0, double ycor = 0);
            Point(const Point& other);
            ~Point();
            Point& operator=(const Point& other);
            double getX() const;
            double getY() const;
            void setX(double);
            void setY(double);
            double distance(const Point& other) const;
            string print();
            static Point moveTowards(const Point& source, const Point& dest, double distance);

            Point(Point&& other) noexcept = default;
            Point& operator=(Point&& other) noexcept = default;

    };
}
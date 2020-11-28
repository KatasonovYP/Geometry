#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include <utility>
#include <vector>
#include <iostream>

namespace Geometry {

    constexpr double EPS = 1e-9;

    class Point {
        public:
        double x, y;
        Point(double x, double y): x(x), y(y) {}
        Point() = default;
        friend std::istream& operator>>(std::istream& in, Point p);
        friend std::ostream& operator<<(std::ostream& out, const Point& p);
    };

    double length(const Point& a, const Point& b);

    std::pair <Point, Point> find_pair_nearest(std::vector <Point> &x);

}

#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

class Point {
    public:
	int x, y;
	Point(int x, int y): x(x), y(y) {}
	Point() = default;
};

double length (const Point& a, const Point& b);

#endif // POINT_HPP
